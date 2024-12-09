int32_t VideoSender::InitializeSender() {
  DCHECK(main_thread_.CalledOnValidThread());
  CriticalSectionScoped cs(_sendCritSect);
  _codecDataBase.ResetSender();
  _encoder = NULL;
  _encodedFrameCallback.SetTransportCallback(NULL);
  _mediaOpt.Reset();  // Resetting frame dropper
  return VCM_OK;
}