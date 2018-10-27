#pragma once

#include "Wrapper.h"
#include "Models.DeviationListItem.h"
#include <winrt/base.h>
#include <winrt/Windows.UI.Xaml.Data.h>

namespace winrt::Da_Art::Models
{
  namespace wfc = winrt::Windows::Foundation::Collections;
  namespace wuxd = winrt::Windows::UI::Xaml::Data;

  template<class T>
  struct InfinityCollection : 
    winrt::implements<wfc::IObservableVector<T>, wfc::IVector<T>, wfc::IVectorView<T>, wfc::IIterable<T>, wuxd::ISupportIncrementalLoading>,
    winrt::observable_vector_base<InfinityCollection<T>, T>
  {

  };
}