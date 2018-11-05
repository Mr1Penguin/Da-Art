//
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "Models.DeviationListItem.h" // for some reason XamlTypeInfo.g.cpp does not compiled without including model here
#include "Models.WatchItemCollection.h"

namespace winrt::Da_Art::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Da_Art::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
