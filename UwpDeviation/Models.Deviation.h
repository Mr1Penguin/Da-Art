//
// Declaration of the Deviation class.
//

#pragma once

#include "Models.Deviation.g.h"
#include "Models.SubModels.Deviation.Flash.g.h"
#include "Models.SubModels.Deviation.Thumb.g.h"
#include "Models.SubModels.Deviation.MotionBook.g.h"
#include "Models.SubModels.Deviation.Video.g.h"

namespace winrt::UwpDeviation::Models::implementation {
  namespace wfc = Windows::Foundation::Collections;

  struct Deviation
      : DeviationT<Deviation>
      , ::apicc::BaseModel {
    Deviation() = default;

    SubModels::Deviation::Flash Flash() const noexcept { return m_flash; }
    void Flash(const SubModels::Deviation::Flash &flash) noexcept { m_flash = flash; }
    SubModels::Deviation::MotionBook MotionBook() const noexcept { return m_motion_book; }
    void MotionBook(const SubModels::Deviation::MotionBook &motion_book) noexcept { m_motion_book = motion_book; }
    wfc::IVector<SubModels::Deviation::Video> Videos() const noexcept { return m_videos; }
    void Videos(const wfc::IVector<SubModels::Deviation::Video> &videos) noexcept { m_videos = videos; }
    apicc::NullableString Excerpt() const noexcept { return m_excerpt; }
    void Excerpt(apicc::NullableString excerpt) noexcept { m_excerpt = excerpt; }
    apicc::NullableString CategoryPath() const noexcept { return m_category_path; }
    void CategoryPath(apicc::NullableString category_path) noexcept { m_category_path = category_path; }
    wfc::IVector<SubModels::Deviation::Thumb> Thumbs() const noexcept { return m_thumbs; }
    void Thumbs(const wfc::IVector<SubModels::Deviation::Thumb> &thumbs) noexcept { m_thumbs = thumbs; }

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;

  private:
    SubModels::Deviation::Flash m_flash;
    SubModels::Deviation::MotionBook m_motion_book;
    wfc::IVector<SubModels::Deviation::Video> m_videos;
    apicc::NullableString m_excerpt;
    apicc::NullableString m_category_path;
    wfc::IVector<SubModels::Deviation::Thumb> m_thumbs;
  };
} // namespace winrt::UwpDeviantart::Models::implementation

namespace winrt::UwpDeviation::Models::factory_implementation {
  struct Deviation : DeviationT<Deviation, implementation::Deviation> {
  };
} // namespace winrt::UwpDeviantart::Models::factory_implementation