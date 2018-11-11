//
// Declaration of the Video class.
//

#pragma once

#include "Models.SubModels.Deviation.Video.g.h"

namespace winrt::UwpDeviation::Models::SubModels::Deviation::implementation {
  struct Video
      : VideoT<Video>
      , ::apicc::BaseModel {
    Video() = default;

    virtual void Serialize([[maybe_unused]] rwriter &writer) override;
    virtual void Deserialize([[maybe_unused]] const rvalue &document) override;
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::implementation

namespace winrt::UwpDeviation::Models::SubModels::Deviation::factory_implementation {
  struct Video : VideoT<Video, implementation::Video> {
  };
} // namespace winrt::UwpDeviantart::Models::SubModels::Deviation::factory_implementation
