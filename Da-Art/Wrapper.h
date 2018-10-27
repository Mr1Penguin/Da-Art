#pragma once

#include <memory>

namespace winrt::Da_Art::Models
{

  template<class T>
  struct Wrapper
  {
    T Item() const noexcept { return m_item; }
    void Item(T item) noexcept { m_item = std::move(item); }
  protected:
    Wrapper() {}
    Wrapper(T item) : m_item(std::move(item)) { }
    virtual ~Wrapper() = 0;
  private:
    T m_item;
  };
}