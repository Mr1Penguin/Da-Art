#pragma once

#include "InfinityCollection.h"
#include "Models.DeviationListItem.g.h"

namespace winrt::Da_Art::Models {
  template <class C>
  struct DeviationCollection : InfinityCollection<C, DeviationListItem> {
    DeviationCollection() = default;

  protected:
    struct Thumb {
      Thumb() = default;
      Thumb(int32_t id, int32_t small_height, int32_t medium_height)
          : id(id), small_height(small_height), medium_height(medium_height)
      {
      }

      int32_t id;
      int32_t small_height;
      int32_t medium_height;

      bool operator==(const Thumb& other)
      {
        return id == other.id && small_height == other.small_height && medium_height == other.medium_height;
      }
      bool operator!=(const Thumb& other) { return !(*this == other); }
    };

    wf::IAsyncOperation<DeviationListItem> AddloadingItem(winrt::apartment_context context) override
    {
      auto item = std::find_if(std::begin(get_container()), std::end(get_container()),
                               [](const DeviationListItem& i) { return i.Type() == DeviationListItemType::Loading; });

      if (item != std::end(get_container())) { co_return* item; }

      auto loading_item = DeviationListItem();
      loading_item.Type(DeviationListItemType::Loading);
      co_await context;
      Append(loading_item);
      co_await winrt::resume_background();
      co_return loading_item;
    }

    void AddItem(/*Deviation deviation*/)
    {
      struct stub {
        bool IsJournal() { return true; }
        winrt::hstring Src() { return L"uri"; }
      };

      stub deviation;

      if (IsUnsupported()) { return; } // maybe better to show something with 'open in browser' option

      if (deviation.IsJournal()) {
        auto item = DeviationListItem{};
        item.Type(DeviationListItemType::Journal);
        /*item.Deviation(deviation);*/
        Append(std::move(item));
      }
      else {
        auto [id, small_height, medium_height] = GetThumb();

        auto item = DeviationListItem{};

        item.Type(DeviationListItemType::Image);
        /*item.Deviation(deviation);*/
        item.ThumbUri(deviation.Src() /*deviation.Thumbs()[id].Src()*/);
        item.SmallThumbHeight(small_height);
        item.MediumThumbHeight(medium_height);
      }
    }

    static int32_t GetHeight(int32_t base_length, int32_t width, int32_t height)
    {
      height = static_cast<int>(height * static_cast<double>(base_length) / width);
      return std::min(height, base_length);
    }

    static Thumb GetThumb(/*Deviation deviation*/)
    {
      struct stub {
        int Width() { return 100; }
        int Height() { return 200; }
      };

      stub deviation;

      auto id = deviation.Width() < 200 * 0.7 /*what is this?*/ ? 1 : 2;
      auto height = GetHeight(100, deviation.Width(), deviation.Height());
      auto med_height = height == 100 ? 198 : 2 * height - 1;
      height = height == 100 ? 98 : 2 * height - 1;
      return {id, height, med_height};
    }

    static bool IsUnsupported(/*Deviation deviation*/) { return false; /*Flash,MotionBook,Videos*/ }

  private:
  };
} // namespace winrt::Da_Art::Models