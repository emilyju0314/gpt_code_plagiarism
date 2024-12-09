bool VCMQmResolution::EvenFrameSize() {
  if (action_.spatial == kOneHalfSpatialUniform) {
    if ((width_ * 3 / 4) % 2 != 0 || (height_ * 3 / 4) % 2 != 0) {
      return false;
    }
  } else if (action_.spatial == kOneQuarterSpatialUniform) {
    if ((width_ * 1 / 2) % 2 != 0 || (height_ * 1 / 2) % 2 != 0) {
      return false;
    }
  }
  return true;
}