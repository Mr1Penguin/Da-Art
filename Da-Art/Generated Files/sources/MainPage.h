#pragma once

#include "MainPage.g.h"

namespace winrt::Da_Art::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Da_Art::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
