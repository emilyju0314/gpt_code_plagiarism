int32_t VPMContentAnalysis::ComputeSpatialMetrics_C() {
  const int sizei = height_;
  const int sizej = width_;

  // Pixel mean square average: used to normalize the spatial metrics.
  uint32_t pixelMSA = 0;

  uint32_t spatialErrSum = 0;
  uint32_t spatialErrVSum = 0;
  uint32_t spatialErrHSum = 0;

  // make sure work section is a multiple of 16
  const int width_end = ((sizej - 2 * border_) & -16) + border_;

  for (int i = border_; i < sizei - border_; i += skip_num_) {
    for (int j = border_; j < width_end; j++) {
      int ssn1 = i * sizej + j;
      int ssn2 = (i + 1) * sizej + j;  // bottom
      int ssn3 = (i - 1) * sizej + j;  // top
      int ssn4 = i * sizej + j + 1;    // right
      int ssn5 = i * sizej + j - 1;    // left

      uint16_t refPixel1 = orig_frame_[ssn1] << 1;
      uint16_t refPixel2 = orig_frame_[ssn1] << 2;

      uint8_t bottPixel = orig_frame_[ssn2];
      uint8_t topPixel = orig_frame_[ssn3];
      uint8_t rightPixel = orig_frame_[ssn4];
      uint8_t leftPixel = orig_frame_[ssn5];

      spatialErrSum += static_cast<uint32_t>(abs(static_cast<int16_t>(
          refPixel2 - static_cast<uint16_t>(bottPixel + topPixel + leftPixel +
                                            rightPixel))));
      spatialErrVSum += static_cast<uint32_t>(abs(static_cast<int16_t>(
          refPixel1 - static_cast<uint16_t>(bottPixel + topPixel))));
      spatialErrHSum += static_cast<uint32_t>(abs(static_cast<int16_t>(
          refPixel1 - static_cast<uint16_t>(leftPixel + rightPixel))));
      pixelMSA += orig_frame_[ssn1];
    }
  }

  // Normalize over all pixels.
  const float spatialErr = static_cast<float>(spatialErrSum >> 2);
  const float spatialErrH = static_cast<float>(spatialErrHSum >> 1);
  const float spatialErrV = static_cast<float>(spatialErrVSum >> 1);
  const float norm = static_cast<float>(pixelMSA);

  // 2X2:
  spatial_pred_err_ = spatialErr / norm;
  // 1X2:
  spatial_pred_err_h_ = spatialErrH / norm;
  // 2X1:
  spatial_pred_err_v_ = spatialErrV / norm;
  return VPM_OK;
}