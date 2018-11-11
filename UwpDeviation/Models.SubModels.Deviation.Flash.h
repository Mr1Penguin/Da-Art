//
// Declaration of the Flash class.
//

#pragma once

#include "Models.SubModels.Deviation.Flash.g.h"

namespace winrt::UwpDeviation::Models::SubModels::Deviation::implementation {
  struct Flash
      : FlashT<Flash>
      , ::apicc::BaseModel {
    Flash() = default;

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::implementation

namespace winrt::UwpDeviation::Models::SubModels::Deviation::factory_implementation {
  struct Flash : FlashT<Flash, implementation::Flash> {
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::factory_implementation
