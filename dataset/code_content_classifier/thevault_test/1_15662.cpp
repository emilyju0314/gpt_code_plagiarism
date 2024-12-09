int32_t VideoSender::RegisterSendCodec(const VideoCodec* sendCodec,
                                       uint32_t numberOfCores,
                                       uint32_t maxPayloadSize) {
  DCHECK(main_thread_.CalledOnValidThread());
  CriticalSectionScoped cs(_sendCritSect);
  if (sendCodec == NULL) {
    return VCM_PARAMETER_ERROR;
  }

  bool ret = _codecDataBase.SetSendCodec(
      sendCodec, numberOfCores, maxPayloadSize, &_encodedFrameCallback);

  // Update encoder regardless of result to make sure that we're not holding on
  // to a deleted instance.
  _encoder = _codecDataBase.GetEncoder();
  // Cache the current codec here so they can be fetched from this thread
  // without requiring the _sendCritSect lock.
  current_codec_ = *sendCodec;

  if (!ret) {
    LOG(LS_ERROR) << "Failed to initialize set encoder with payload name '"
                  << sendCodec->plName << "'.";
    return VCM_CODEC_ERROR;
  }

  int numLayers = (sendCodec->codecType != kVideoCodecVP8)
                      ? 1
                      : sendCodec->codecSpecific.VP8.numberOfTemporalLayers;
  // If we have screensharing and we have layers, we disable frame dropper.
  bool disable_frame_dropper =
      numLayers > 1 && sendCodec->mode == kScreensharing;
  if (disable_frame_dropper) {
    _mediaOpt.EnableFrameDropper(false);
  } else if (frame_dropper_enabled_) {
    _mediaOpt.EnableFrameDropper(true);
  }
  _nextFrameTypes.clear();
  _nextFrameTypes.resize(VCM_MAX(sendCodec->numberOfSimulcastStreams, 1),
                         kVideoFrameDelta);

  _mediaOpt.SetEncodingData(sendCodec->codecType,
                            sendCodec->maxBitrate * 1000,
                            sendCodec->maxFramerate * 1000,
                            sendCodec->startBitrate * 1000,
                            sendCodec->width,
                            sendCodec->height,
                            numLayers,
                            maxPayloadSize);
  return VCM_OK;
}