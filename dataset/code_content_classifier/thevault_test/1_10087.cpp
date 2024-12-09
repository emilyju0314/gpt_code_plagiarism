void VCMQmResolution::SelectSpatialDirectionMode(float transition_rate) {
  // Default is 4/3x4/3
  // For bit rates well below transitional rate, we select 2x2.
  if (avg_target_rate_ < transition_rate * kRateRedSpatial2X2) {
    qm_->spatial_width_fact = 2.0f;
    qm_->spatial_height_fact = 2.0f;
  }
  // Otherwise check prediction errors and aspect ratio.
  float spatial_err = 0.0f;
  float spatial_err_h = 0.0f;
  float spatial_err_v = 0.0f;
  if (content_metrics_) {
    spatial_err = content_metrics_->spatial_pred_err;
    spatial_err_h = content_metrics_->spatial_pred_err_h;
    spatial_err_v = content_metrics_->spatial_pred_err_v;
  }

  // Favor 1x2 if aspect_ratio is 16:9.
  if (aspect_ratio_ >= 16.0f / 9.0f) {
    // Check if 1x2 has lowest prediction error.
    if (spatial_err_h < spatial_err && spatial_err_h < spatial_err_v) {
      qm_->spatial_width_fact = 2.0f;
      qm_->spatial_height_fact = 1.0f;
    }
  }
  // Check for 4/3x4/3 selection: favor 2x2 over 1x2 and 2x1.
  if (spatial_err < spatial_err_h * (1.0f + kSpatialErr2x2VsHoriz) &&
      spatial_err < spatial_err_v * (1.0f + kSpatialErr2X2VsVert)) {
    qm_->spatial_width_fact = 4.0f / 3.0f;
    qm_->spatial_height_fact = 4.0f / 3.0f;
  }
  // Check for 2x1 selection.
  if (spatial_err_v < spatial_err_h * (1.0f - kSpatialErrVertVsHoriz) &&
      spatial_err_v < spatial_err * (1.0f - kSpatialErr2X2VsVert)) {
    qm_->spatial_width_fact = 1.0f;
    qm_->spatial_height_fact = 2.0f;
  }
}