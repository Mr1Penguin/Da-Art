#pragma once

#include "Class.g.h"
#include "Models.Deviation.g.h"

namespace winrt::UwpDeviation::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);

        UwpDeviation::Models::Deviation Stub() { return UwpDeviation::Models::Deviation(); }
    };
}

namespace winrt::UwpDeviation::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
