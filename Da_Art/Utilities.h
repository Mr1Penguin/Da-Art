#pragma once

namespace winrt::Da_Art {
  bool is_null_or_empty(const winrt::apicc::NullableString& string);
  bool is_journal(const UwpDeviation::Models::Deviation& deviation);
  bool is_unsupported(const UwpDeviation::Models::Deviation& deviation);
} // namespace winrt::Da_Art