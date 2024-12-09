float VCMQmRobustness::AdjustFecFactor(uint8_t code_rate_delta,
                                       float total_rate,
                                       float framerate,
                                       int64_t rtt_time,
                                       uint8_t packet_loss) {
  // Default: no adjustment
  float adjust_fec = 1.0f;
  if (content_metrics_ == NULL) {
    return adjust_fec;
  }
  // Compute class state of the content.
  ComputeMotionNFD();
  ComputeSpatial();

  // TODO(marpan): Set FEC adjustment factor.

  // Keep track of previous values of network state:
  // adjustment may be also based on pattern of changes in network state.
  prev_total_rate_ = total_rate;
  prev_rtt_time_ = rtt_time;
  prev_packet_loss_ = packet_loss;
  prev_code_rate_delta_ = code_rate_delta;
  return adjust_fec;
}