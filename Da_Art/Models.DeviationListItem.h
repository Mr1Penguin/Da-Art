//
// Declaration of the DeviationListItem class.
//

#pragma once

#include "Models.DeviationListItem.g.h"

namespace winrt::Da_Art::Models::implementation {
  struct DeviationListItem : DeviationListItemT<DeviationListItem> {
    DeviationListItem() = default;
    DeviationListItemType Type() { return m_type; }
    void Type(DeviationListItemType type) { m_type = type; }
    winrt::hstring ThumbUri() { return m_thumb_uri; }
    void ThumbUri(winrt::hstring thumb_uri) { m_thumb_uri = std::move(thumb_uri); }
    double SmallThumbHeight() { return m_small_thumb_height; }
    void SmallThumbHeight(double small_thumb_height) { m_small_thumb_height = small_thumb_height; }
    double MediumThumbHeight() const noexcept { return m_medium_thumb_height; }
    void MediumThumbHeight(double medium_thumb_height) noexcept { m_medium_thumb_height = medium_thumb_height; }
    UwpDeviation::Models::Deviation Deviation() const noexcept { return m_deviation; }
    void Deviation(UwpDeviation::Models::Deviation deviation) noexcept { m_deviation = deviation; }

  private:
    DeviationListItemType m_type;
    // model
    winrt::hstring m_thumb_uri;
    double m_small_thumb_height;
    double m_medium_thumb_height;
    UwpDeviation::Models::Deviation m_deviation{nullptr};
  };
} // namespace winrt::Da_Art::Models::implementation

namespace winrt::Da_Art::Models::factory_implementation {
  struct DeviationListItem : DeviationListItemT<DeviationListItem, implementation::DeviationListItem> {
  };
} // namespace winrt::Da_Art::Models::factory_implementation
