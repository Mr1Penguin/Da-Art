#include "pch.h"

#include "Models.Pageable.h"

using namespace winrt;

namespace winrt::UwpDeviation::Models::implementation {
  void Pageable::Serialize([[maybe_unused]] rwriter &writer)
  {
    BaseModel::Serialize(writer);
    Write(m_cursor, writer, L"cursor");
    Write(m_has_more, writer, L"has_more");
  }

  void Pageable::Deserialize([[maybe_unused]] const rvalue &document) {
    BaseModel::Deserialize(document);
    m_cursor = Read<decltype(m_cursor)>(document, L"cursor");
    m_has_more = Read<decltype(m_has_more)>(document, L"has_more");
  }
} // namespace winrt::UwpDeviation::Models::implementation