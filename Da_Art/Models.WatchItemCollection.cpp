﻿#include "pch.h"

#include "Models.WatchItemCollection.h"
#include "Utilities.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Da_Art::Models {
  struct FeedItem {
  };
} // namespace winrt::Da_Art::Models

namespace {
  namespace wfc = winrt::Windows::Foundation::Collections;

  std::vector<winrt::Da_Art::Models::DeviationListItem>
  filter_items(const wfc::IVector<winrt::Da_Art::Models::DeviationListItem>& input)
  {
    std::vector<winrt::Da_Art::Models::DeviationListItem> filtered;
    filtered.reserve(input.Size());

    for (auto it = input.First(); it.HasCurrent(); ++it) {
      if (winrt::Da_Art::is_unsupported((*it).Deviation())) { filtered.push_back(*it); }
    }

    return filtered;
  }
} // namespace

namespace winrt::Da_Art::Models::implementation {
  wf::IAsyncOperation<wuxd::LoadMoreItemsResult> WatchItemCollection::LoadItems(uint32_t count,
                                                                                winrt::apartment_context context)
  {
    co_await winrt::resume_background();
    //(re)create HomeRequest

    if (!HasMoreItems()) {
      auto lmir = wuxd::LoadMoreItemsResult{};
      lmir.Count = 0;
      co_return lmir;
    }

    HasMoreItems(false);
    // HomeRequest.Cursor = Cursor;

    // combined token

    auto loading_item = co_await AddloadingItem(context);
    // get from web

    // if error

    auto response = winrt::single_threaded_vector<winrt::Da_Art::Models::DeviationListItem>(); // replace to FeedItem
    auto filtered = filter_items(response);

    co_await context;
    RemoveLoadingItem(loading_item);
    std::for_each(std::execution::seq, std::begin(filtered), std::end(filtered),
                  [this](const Models::DeviationListItem& item) { AddItem(item); });
    co_await winrt::resume_background();

    if (filtered.size() == 0 && Size() == 0) { /*NoResults ?.Invoke(this, null);*/
    }

    HasMoreItems(true /*from response*/);
    Cursor(L"" /*from response*/);

    auto lmir = wuxd::LoadMoreItemsResult{};
    assert(filtered.size() <= std::numeric_limits<uint32_t>::max());
    lmir.Count = static_cast<uint32_t>(filtered.size());
    return lmir;
  }

  void WatchItemCollection::AddItem(const winrt::Da_Art::Models::DeviationListItem& /*item*/) // replace to FeedItem
  {
  }
} // namespace winrt::Da_Art::Models::implementation
