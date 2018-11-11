//
// Declaration of the Thumb class.
//

#pragma once

#include "Models.SubModels.Deviation.Thumb.g.h"

namespace winrt::UwpDeviation::Models::SubModels::Deviation::implementation {
  struct Thumb
      : ThumbT<Thumb>
      , ::apicc::BaseModel {
    Thumb() = default;
    winrt::hstring Src() const noexcept { return m_src; }
    void Src(const winrt::hstring &src) noexcept { m_src = src; }
    int32_t Width() const noexcept { return m_width; }
    void Width(int32_t width) noexcept { m_width = width; }
    int32_t Height() const noexcept { return m_height; }
    void Height(int32_t height) noexcept { m_height = height; }

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;

  private:
    winrt::hstring m_src;
    int32_t m_width;
    int32_t m_height;
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::implementation

namespace winrt::UwpDeviation::Models::SubModels::Deviation::factory_implementation {
  struct Thumb : ThumbT<Thumb, implementation::Thumb> {
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::factory_implementation
