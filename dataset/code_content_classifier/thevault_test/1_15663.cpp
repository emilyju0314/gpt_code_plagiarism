int32_t VideoSender::RegisterExternalEncoder(VideoEncoder* externalEncoder,
                                             uint8_t payloadType,
                                             bool internalSource /*= false*/) {
  DCHECK(main_thread_.CalledOnValidThread());

  CriticalSectionScoped cs(_sendCritSect);

  if (externalEncoder == NULL) {
    bool wasSendCodec = false;
    const bool ret =
        _codecDataBase.DeregisterExternalEncoder(payloadType, &wasSendCodec);
    if (wasSendCodec) {
      // Make sure the VCM doesn't use the de-registered codec
      _encoder = NULL;
    }
    return ret ? 0 : -1;
  }
  _codecDataBase.RegisterExternalEncoder(
      externalEncoder, payloadType, internalSource);
  return 0;
}