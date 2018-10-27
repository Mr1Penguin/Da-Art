﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"
#include "MainPage.h"

#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter

namespace winrt::Da_Art::implementation
{
    using Application = ::winrt::Windows::UI::Xaml::Application;
    using ComponentResourceLocation = ::winrt::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation;
    using DataTemplate = ::winrt::Windows::UI::Xaml::DataTemplate;
    using DependencyObject = ::winrt::Windows::UI::Xaml::DependencyObject;
    using DependencyProperty = ::winrt::Windows::UI::Xaml::DependencyProperty;
    using IComponentConnector = ::winrt::Windows::UI::Xaml::Markup::IComponentConnector;
    using Uri = ::winrt::Windows::Foundation::Uri;
    using XamlBindingHelper = ::winrt::Windows::UI::Xaml::Markup::XamlBindingHelper;

    template <typename D, typename ... I>
    void MainPageT<D, I...>::InitializeComponent()
    {
        if (!_contentLoaded)
        {
            _contentLoaded = true;
            Uri resourceLocator{ L"ms-appx:///MainPage.xaml" };
            Application::LoadComponent(*this, resourceLocator, ComponentResourceLocation::Application);
        }
    }

    template <typename D, typename ... I>
    void MainPageT<D, I...>::Connect(int32_t connectionId, IInspectable const& target)
    {
        switch (connectionId)
        {
        case 2:
            {
                auto targetElement = target.as<::winrt::Windows::UI::Xaml::Controls::Button>();
                this->myButton(targetElement);
                auto weakThis = ::winrt::make_weak<class_type>(*this);
                targetElement.Click([weakThis](::winrt::Windows::Foundation::IInspectable const& p0, ::winrt::Windows::UI::Xaml::RoutedEventArgs const& p1){
                    if (auto t = weakThis.get())
                    {
                        ::winrt::get_self<D>(t)->ClickHandler(p0, p1);
                    }
                });
            }
            break;
        }
        _contentLoaded = true;
    }

    template <typename D, typename ... I>
    void MainPageT<D, I...>::DisconnectUnloadedObject(int32_t)
    {
        throw ::winrt::hresult_invalid_argument { L"No unloadable objects to disconnect." };
    }

    template <typename D, typename ... I>
    void MainPageT<D, I...>::UnloadObject(DependencyObject const&)
    {
        throw ::winrt::hresult_invalid_argument { L"No unloadable objects." };
    }


    template <typename D, typename... I>
    IComponentConnector MainPageT<D, I...>::GetBindingConnector(int32_t, IInspectable const&)
    {
        return nullptr;
    }

    template struct MainPageT<struct MainPage>;
}


#pragma warning(pop)


