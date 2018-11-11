//
// Declaration of the BaseModel class.
//

#pragma once

#include "Models.BaseModel.g.h"

namespace wfc = winrt::Windows::Foundation::Collections;

namespace winrt::UwpDeviation::Models::implementation {
  struct BaseModel
      : BaseModelT<BaseModel>
      , ::apicc::BaseModel {
    BaseModel() = default;

    winrt::hstring Status() const noexcept { return m_status; }
    void Status(const winrt::hstring& status) noexcept { m_status = status; }
    apicc::NullableString Error() const noexcept { return m_error; }
    void Error(apicc::NullableString error) noexcept { m_error = error; }
    winrt::hstring ErrorDescription() const noexcept { return m_error_description; }
    void ErrorDescription(const winrt::hstring& error_description) noexcept { m_error_description = error_description; }
    int32_t ErrorCode() const noexcept { return m_error_code; }
    void ErrorCode(int32_t error_code) noexcept { m_error_code = error_code; }
    wfc::IMap<winrt::hstring, winrt::hstring> ErrorDetails() const noexcept { return m_error_details; }
    void ErrorDetails(const wfc::IMap<winrt::hstring, winrt::hstring>& error_details) noexcept
    {
      m_error_details = error_details;
    }

    virtual void Serialize([[maybe_unused]] rwriter& writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue& document) override;

  private:
    winrt::hstring m_status;
    apicc::NullableString m_error;
    winrt::hstring m_error_description;
    int32_t m_error_code;
    wfc::IMap<winrt::hstring, winrt::hstring> m_error_details;
  };
} // namespace winrt::UwpDeviation::Models::implementation

namespace winrt::UwpDeviation::Models::factory_implementation {
  struct BaseModel : BaseModelT<BaseModel, implementation::BaseModel> {
  };
} // namespace winrt::UwpDeviation::Models::factory_implementation
