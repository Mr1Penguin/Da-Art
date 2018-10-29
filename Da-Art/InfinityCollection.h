#pragma once

#include "Wrapper.h"
#include <vector>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/base.h>

namespace winrt::Da_Art::Models {
  namespace wf = winrt::Windows::Foundation;
  namespace wfc = winrt::Windows::Foundation::Collections;
  namespace wuc = winrt::Windows::UI::Core;
  namespace wuxd = winrt::Windows::UI::Xaml::Data;

  template <class C, class T>
  struct InfinityCollection : winrt::observable_vector_base<C, T> {
    auto& get_container() const noexcept { return m_values; }
    auto& get_container() noexcept { return m_values; }

    bool HasMoreItems() const noexcept { return m_has_more_items; }
    wf::IAsyncAction ContinueLoadingAsync()
    {
      HasMoreItems(true);
      co_await winrt::resume_background();
      LoadMoreItemsAsync(1);
    }
    wf::IAsyncOperation<wuxd::LoadMoreItemsResult> LoadMoreItemsAsync(uint32_t count)
    {
      winrt::apartment_context ui_thread;
      return LoadItems(count, ui_thread);
    }

  protected:
    void HasMoreItems(bool has_more_items) noexcept { m_has_more_items = has_more_items; }
    virtual wf::IAsyncOperation<wuxd::LoadMoreItemsResult> LoadItems(uint32_t count,
                                                                     winrt::apartment_context context) = 0;
    virtual wf::IAsyncOperation<T> AddloadingItem(winrt::apartment_context context) = 0;
    void RemoveLoadingItem(T item, bool isError = false, winrt::hstring errorText = L"")
    {
      uint32_t index;
      if (IndexOf(item, index)) { RemoveAt(index); }
      if (!isError) { return; }

      // TODO: propagate error
      // ErrorOnLoading?.Invoke(this, null);
      // Send event using global message queue
    }

  private:
    bool m_has_more_items;
    std::vector<T> m_values;
  };
} // namespace winrt::Da_Art::Models
