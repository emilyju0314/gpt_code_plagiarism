int VCMQmResolution::SelectResolution(VCMResolutionScale** qm) {
  if (!init_) {
    return VCM_UNINITIALIZED;
  }
  if (content_metrics_ == NULL) {
    Reset();
    *qm = qm_;
    return VCM_OK;
  }

  // Check conditions on down-sampling state.
  assert(state_dec_factor_spatial_ >= 1.0f);
  assert(state_dec_factor_temporal_ >= 1.0f);
  assert(state_dec_factor_spatial_ <= kMaxSpatialDown);
  assert(state_dec_factor_temporal_ <= kMaxTempDown);
  assert(state_dec_factor_temporal_ * state_dec_factor_spatial_ <=
         kMaxTotalDown);

  // Compute content class for selection.
  content_class_ = ComputeContentClass();
  // Compute various rate quantities for selection.
  ComputeRatesForSelection();

  // Get the encoder state.
  ComputeEncoderState();

  // Default settings: no action.
  SetDefaultAction();
  *qm = qm_;

  // Check for going back up in resolution, if we have had some down-sampling
  // relative to native state in Initialize().
  if (down_action_history_[0].spatial != kNoChangeSpatial ||
      down_action_history_[0].temporal != kNoChangeTemporal) {
    if (GoingUpResolution()) {
      *qm = qm_;
      return VCM_OK;
    }
  }

  // Check for going down in resolution.
  if (GoingDownResolution()) {
    *qm = qm_;
    return VCM_OK;
  }
  return VCM_OK;
}