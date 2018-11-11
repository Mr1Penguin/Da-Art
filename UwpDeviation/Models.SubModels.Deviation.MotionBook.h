//
// Declaration of the MotionBook class.
//

#pragma once

#include "Models.SubModels.Deviation.MotionBook.g.h"

namespace winrt::UwpDeviation::Models::SubModels::Deviation::implementation {
  struct MotionBook
      : MotionBookT<MotionBook>
      , ::apicc::BaseModel {
    MotionBook() = default;

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::implementation

namespace winrt::UwpDeviation::Models::SubModels::Deviation::factory_implementation {
  struct MotionBook : MotionBookT<MotionBook, implementation::MotionBook> {
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::factory_implementation
