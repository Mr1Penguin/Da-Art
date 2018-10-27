//
// Declaration of the DeviationListItem class.
//

#pragma once

#include "Models.DeviationListItem.g.h"

namespace winrt::Da_Art::Models::implementation
{
    struct DeviationListItem : DeviationListItemT<DeviationListItem>
    {
        DeviationListItem() = default;
    };
}

namespace winrt::Da_Art::Models::factory_implementation
{
    struct DeviationListItem : DeviationListItemT<DeviationListItem, implementation::DeviationListItem>
    {
    };
}
