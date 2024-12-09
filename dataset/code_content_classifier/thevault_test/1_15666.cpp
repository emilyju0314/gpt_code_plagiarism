int32_t VideoSender::AddVideoFrame(const I420VideoFrame& videoFrame,
                                   const VideoContentMetrics* contentMetrics,
                                   const CodecSpecificInfo* codecSpecificInfo) {
  CriticalSectionScoped cs(_sendCritSect);
  if (_encoder == NULL) {
    return VCM_UNINITIALIZED;
  }
  // TODO(holmer): Add support for dropping frames per stream. Currently we
  // only have one frame dropper for all streams.
  if (_nextFrameTypes[0] == kFrameEmpty) {
    return VCM_OK;
  }
  if (_mediaOpt.DropFrame()) {
    return VCM_OK;
  }
  _mediaOpt.UpdateContentData(contentMetrics);
  // TODO(pbos): Make sure setting send codec is synchronized with video
  // processing so frame size always matches.
  if (!_codecDataBase.MatchesCurrentResolution(videoFrame.width(),
                                               videoFrame.height())) {
    LOG(LS_ERROR) << "Incoming frame doesn't match set resolution. Dropping.";
    return VCM_PARAMETER_ERROR;
  }
  int32_t ret =
      _encoder->Encode(videoFrame, codecSpecificInfo, _nextFrameTypes);
  recorder_->Add(videoFrame);
  if (ret < 0) {
    LOG(LS_ERROR) << "Failed to encode frame. Error code: " << ret;
    return ret;
  }
  for (size_t i = 0; i < _nextFrameTypes.size(); ++i) {
    _nextFrameTypes[i] = kVideoFrameDelta;  // Default frame type.
  }
  return VCM_OK;
}