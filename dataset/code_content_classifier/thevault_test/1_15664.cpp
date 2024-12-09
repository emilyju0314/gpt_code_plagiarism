int32_t VideoSender::RegisterVideoQMCallback(
    VCMQMSettingsCallback* qm_settings_callback) {
  CriticalSectionScoped cs(_sendCritSect);
  DCHECK(qm_settings_callback_ == qm_settings_callback ||
         !qm_settings_callback_ ||
         !qm_settings_callback) << "Overwriting the previous callback?";
  qm_settings_callback_ = qm_settings_callback;
  _mediaOpt.EnableQM(qm_settings_callback_ != NULL);
  return VCM_OK;
}