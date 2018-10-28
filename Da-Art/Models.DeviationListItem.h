//
// Declaration of the DeviationListItem class.
//

#pragma once

#include "Models.DeviationListItem.g.h"

/*
public enum ItemType
        {
            Image,
            Journal,
            Loading
        }

        public ItemType Type { get; set; }

        public DeviantartApi.Objects.Deviation Deviation { get; set; }
        public string ThumbUri { get; set; }
        public double SmallThumbHeight { get; set; }
public double MediumThumbHeight { get; set; }
*/

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

  private:
    DeviationListItemType m_type;
    // model
    winrt::hstring m_thumb_uri;
    double m_small_thumb_height;
    double m_medium_thumb_height;
  };
} // namespace winrt::Da_Art::Models::implementation

namespace winrt::Da_Art::Models::factory_implementation {
  struct DeviationListItem : DeviationListItemT<DeviationListItem, implementation::DeviationListItem> {
  };
} // namespace winrt::Da_Art::Models::factory_implementation
