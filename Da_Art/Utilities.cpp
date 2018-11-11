#include <pch.h>

#include "Utilities.h"

namespace winrt::Da_Art {
  bool is_null_or_empty(const winrt::apicc::NullableString& string) { return string.IsNull || string.Value.empty(); }

  bool is_journal(const UwpDeviation::Models::Deviation& deviation)
  {
    return !is_null_or_empty(deviation.Excerpt()) && !is_null_or_empty(deviation.CategoryPath()) &&
           std::wstring(deviation.CategoryPath().Value).find(L"ournal") != std::wstring::npos;
  }

  bool is_unsupported(const UwpDeviation::Models::Deviation& deviation)
  {
    return deviation.Flash() != nullptr || deviation.MotionBook() != nullptr || deviation.Videos() != nullptr;
  }

} // namespace winrt::Da_Art