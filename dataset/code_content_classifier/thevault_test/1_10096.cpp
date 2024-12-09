int32_t VPMContentAnalysis::TemporalDiffMetric_C() {
  // size of original frame
  int sizei = height_;
  int sizej = width_;
  uint32_t tempDiffSum = 0;
  uint32_t pixelSum = 0;
  uint64_t pixelSqSum = 0;

  uint32_t num_pixels = 0;  // Counter for # of pixels.
  const int width_end = ((width_ - 2 * border_) & -16) + border_;

  for (int i = border_; i < sizei - border_; i += skip_num_) {
    for (int j = border_; j < width_end; j++) {
      num_pixels += 1;
      int ssn = i * sizej + j;

      uint8_t currPixel = orig_frame_[ssn];
      uint8_t prevPixel = prev_frame_[ssn];

      tempDiffSum +=
          static_cast<uint32_t>(abs((int16_t)(currPixel - prevPixel)));
      pixelSum += static_cast<uint32_t>(currPixel);
      pixelSqSum += static_cast<uint64_t>(currPixel * currPixel);
    }
  }

  // Default.
  motion_magnitude_ = 0.0f;

  if (tempDiffSum == 0)
    return VPM_OK;

  // Normalize over all pixels.
  float const tempDiffAvg =
      static_cast<float>(tempDiffSum) / static_cast<float>(num_pixels);
  float const pixelSumAvg =
      static_cast<float>(pixelSum) / static_cast<float>(num_pixels);
  float const pixelSqSumAvg =
      static_cast<float>(pixelSqSum) / static_cast<float>(num_pixels);
  float contrast = pixelSqSumAvg - (pixelSumAvg * pixelSumAvg);

  if (contrast > 0.0) {
    contrast = sqrt(contrast);
    motion_magnitude_ = tempDiffAvg / contrast;
  }
  return VPM_OK;
}