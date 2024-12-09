void VCMQmResolution::AdjustAction() {
  // If the spatial level is default state (neither low or high), motion level
  // is not high, and spatial action was selected, switch to 2/3 frame rate
  // reduction if the average incoming frame rate is high.
  if (spatial_.level == kDefault && motion_.level != kHigh &&
      action_.spatial != kNoChangeSpatial &&
      framerate_level_ == kFrameRateHigh) {
    action_.spatial = kNoChangeSpatial;
    action_.temporal = kTwoThirdsTemporal;
  }
  // If both motion and spatial level are low, and temporal down action was
  // selected, switch to spatial 3/4x3/4 if the frame rate is not above the
  // lower middle level (|kFrameRateMiddle1|).
  if (motion_.level == kLow && spatial_.level == kLow &&
      framerate_level_ <= kFrameRateMiddle1 &&
      action_.temporal != kNoChangeTemporal) {
    action_.spatial = kOneHalfSpatialUniform;
    action_.temporal = kNoChangeTemporal;
  }
  // If spatial action is selected, and there has been too much spatial
  // reduction already (i.e., 1/4), then switch to temporal action if the
  // average frame rate is not low.
  if (action_.spatial != kNoChangeSpatial &&
      down_action_history_[0].spatial == kOneQuarterSpatialUniform &&
      framerate_level_ != kFrameRateLow) {
    action_.spatial = kNoChangeSpatial;
    action_.temporal = kTwoThirdsTemporal;
  }
  // Never use temporal action if number of temporal layers is above 2.
  if (num_layers_ > 2) {
    if (action_.temporal != kNoChangeTemporal) {
      action_.spatial = kOneHalfSpatialUniform;
    }
    action_.temporal = kNoChangeTemporal;
  }
  // If spatial action was selected, we need to make sure the frame sizes
  // are multiples of two. Otherwise switch to 2/3 temporal.
  if (action_.spatial != kNoChangeSpatial && !EvenFrameSize()) {
    action_.spatial = kNoChangeSpatial;
    // Only one action (spatial or temporal) is allowed at a given time, so need
    // to check whether temporal action is currently selected.
    action_.temporal = kTwoThirdsTemporal;
  }
}