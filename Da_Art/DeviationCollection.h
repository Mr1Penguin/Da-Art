#pragma once

#include "InfinityCollection.h"
#include "Models.DeviationListItem.g.h"
#include "Utilities.h"

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

    virtual wf::IAsyncOperation<DeviationListItem> AddloadingItem(winrt::apartment_context context) override
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

    void AddItem(UwpDeviation::Models::Deviation deviation)
    {
      if (IsUnsupported(deviation)) { return; } // maybe better to show something with 'open in browser' option

      auto item = DeviationListItem{};

      if (is_journal(deviation)) {
        item.Type(DeviationListItemType::Journal);
        item.Deviation(deviation);
      }
      else {
        auto [id, small_height, medium_height] = GetThumb(deviation);

        auto item = DeviationListItem{};

        item.Type(DeviationListItemType::Image);
        item.Deviation(deviation);
        item.ThumbUri(deviation.Thumbs()[id].Src());
        item.SmallThumbHeight(small_height);
        item.MediumThumbHeight(medium_height);
      }

      Append(std::move(item));
    }

    static int32_t GetHeight(int32_t base_length, int32_t width, int32_t height)
    {
      height = static_cast<int>(height * static_cast<double>(base_length) / width);
      return std::min(height, base_length);
    }

    static Thumb GetThumb(UwpDeviation::Models::Deviation deviation)
    {
      auto id = deviation.Width() < 200 * 0.7 /*what is this?*/ ? 1 : 2;
      auto height = GetHeight(100, deviation.Width(), deviation.Height());
      auto med_height = height == 100 ? 198 : 2 * height - 1;
      height = height == 100 ? 98 : 2 * height - 1;
      return {id, height, med_height};
    }
  private:
  };
} // namespace winrt::Da_Art::Models