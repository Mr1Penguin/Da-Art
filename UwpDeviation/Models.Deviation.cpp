#include "pch.h"

#include "Models.Deviation.h"

#include "Models.SubModels.Deviation.Flash.h"
#include "Models.SubModels.Deviation.MotionBook.h"
#include "Models.SubModels.Deviation.Thumb.h"
#include "Models.SubModels.Deviation.Video.h"

using namespace winrt;

namespace winrt::UwpDeviation::Models::implementation {
  void Deviation::Serialize([[maybe_unused]] rwriter &writer)
  {
    BaseModel::Serialize(writer);
    Write(get_self<SubModels::Deviation::implementation::Flash>(m_flash), writer, L"flash");
    Write<SubModels::Deviation::implementation::Video>(m_videos, writer, L"videos");
    Write(get_self<SubModels::Deviation::implementation::MotionBook>(m_motion_book), writer, L"motion_book");
    Write<SubModels::Deviation::implementation::Thumb>(m_thumbs, writer, L"thumbs");
    Write(m_excerpt, writer, L"excerpt");
    Write(m_category_path, writer, L"category_path");
  }

  void Deviation::Deserialize([[maybe_unused]] const rvalue &document)
  {
    BaseModel::Deserialize(document);
    m_flash = Read<SubModels::Deviation::implementation::Flash>(document, L"flash");
    m_videos = Read<TVec<SubModels::Deviation::implementation::Video>>(document, L"videos");
    m_motion_book = Read<SubModels::Deviation::implementation::MotionBook>(document, L"motion_book");
    m_thumbs = Read<TVec<SubModels::Deviation::implementation::Thumb>>(document, L"thumbs");
    m_excerpt = Read<apicc::NullableString>(document, L"excerpt");
    m_category_path = Read<apicc::NullableString>(document, L"category_path");
  }
} // namespace winrt::UwpDeviation::Models::implementation