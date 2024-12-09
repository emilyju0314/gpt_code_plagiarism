int32_t VCMTiming::MaxDecodeTimeMs(
    FrameType frame_type /*= kVideoFrameDelta*/) const {
  const int32_t decode_time_ms = codec_timer_.RequiredDecodeTimeMs(frame_type);
  assert(decode_time_ms >= 0);
  return decode_time_ms;
}