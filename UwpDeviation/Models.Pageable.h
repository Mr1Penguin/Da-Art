//
// Declaration of the Pageable class.
//

#pragma once

#include "Models.BaseModel.h"
#include "Models.Pageable.g.h"

namespace winrt::UwpDeviation::Models::implementation {
  struct Pageable : PageableT<Pageable, BaseModel> {
    Pageable() = default;

    winrt::hstring Cursor() const noexcept { return m_cursor; }
    void Cursor(const winrt::hstring& cursor) noexcept { m_cursor = cursor; }
    bool HasMore() const noexcept { return m_has_more; }
    void HasMore(bool has_more) noexcept { m_has_more = has_more; }

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;
    
  private:
    winrt::hstring m_cursor;
    bool m_has_more;
  };
} // namespace winrt::UwpDeviation::Models::implementation

namespace winrt::UwpDeviation::Models::factory_implementation {
  struct Pageable : PageableT<Pageable, implementation::Pageable> {
  };
} // namespace winrt::UwpDeviation::Models::factory_implementation
