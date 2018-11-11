//
// Declaration of the WatchItemCollection class.
//

#pragma once

#include "Models.WatchItemCollection.g.h"
#include "DeviationCollection.h"

namespace winrt::Da_Art::Models::implementation
{
  struct WatchItemCollection
      : WatchItemCollectionT<WatchItemCollection>
      , DeviationCollection<WatchItemCollection> {
    WatchItemCollection() = default;

    winrt::hstring Cursor() const noexcept { return m_cursor; }
    void Cursor(const winrt::hstring cursor) noexcept { m_cursor = std::move(cursor); }
    wf::IReference<uint32_t> Offset() const noexcept { return m_offset; }
    void Offset(wf::IReference<uint32_t> offset) noexcept { m_offset = std::move(offset); }

  protected:
    virtual wf::IAsyncOperation<wuxd::LoadMoreItemsResult> LoadItems(uint32_t count, winrt::apartment_context context);

  private:
    // HomeRequest m_home_request;
    winrt::hstring m_cursor;
    wf::IReference<uint32_t> m_offset;

    void AddItem(const winrt::Da_Art::Models::DeviationListItem& item); // replace to FeedItem
  };
}

namespace winrt::Da_Art::Models::factory_implementation {
    struct WatchItemCollection : WatchItemCollectionT<WatchItemCollection, implementation::WatchItemCollection>
    {
    };
}
