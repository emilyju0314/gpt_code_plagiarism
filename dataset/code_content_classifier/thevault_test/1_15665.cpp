int32_t VideoSender::RegisterProtectionCallback(
    VCMProtectionCallback* protection_callback) {
  CriticalSectionScoped cs(_sendCritSect);
  DCHECK(protection_callback_ == protection_callback ||
         !protection_callback_ ||
         !protection_callback) << "Overwriting the previous callback?";
  protection_callback_ = protection_callback;
  return VCM_OK;
}