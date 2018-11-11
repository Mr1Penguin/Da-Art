#include "pch.h"

#include "Models.BaseModel.h"

using namespace winrt;

namespace winrt::UwpDeviation::Models::implementation
{
  void BaseModel::Serialize([[maybe_unused]] rwriter &writer)
  {
    Write(m_status, writer, L"status");
    Write(m_error, writer, L"error");
    Write(m_error_description, writer, L"error_description");
    Write(m_error_code, writer, L"error_code");
    //error_details will be later
  }

  void BaseModel::Deserialize([[maybe_unused]] const rvalue &document)
  {
    m_status = Read<decltype(m_status)>(document, L"status");
    m_error = Read<decltype(m_error)>(document, L"error");
    m_error_description = Read<decltype(m_error_description)>(document, L"error_description");
    m_error_code = Read<decltype(m_error_code)>(document, L"error_code");
    // error_details will be later
  }
}
