void VCMQmResolution::UpdateRates(float target_bitrate,
                                  float encoder_sent_rate,
                                  float incoming_framerate,
                                  uint8_t packet_loss) {
  // Sum the target bitrate: this is the encoder rate from previous update
  // (~1sec), i.e, before the update for next ~1sec.
  sum_target_rate_ += target_bitrate_;
  update_rate_cnt_++;

  // Sum the received (from RTCP reports) packet loss rates.
  sum_packet_loss_ += static_cast<float>(packet_loss / 255.0);

  // Sum the sequence rate mismatch:
  // Mismatch here is based on the difference between the target rate
  // used (in previous ~1sec) and the average actual encoding rate measured
  // at previous ~1sec.
  float diff = target_bitrate_ - encoder_sent_rate;
  if (target_bitrate_ > 0.0)
    sum_rate_MM_ += fabs(diff) / target_bitrate_;
  int sgnDiff = diff > 0 ? 1 : (diff < 0 ? -1 : 0);
  // To check for consistent under(+)/over_shooting(-) of target rate.
  sum_rate_MM_sgn_ += sgnDiff;

  // Update with the current new target and frame rate:
  // these values are ones the encoder will use for the current/next ~1sec.
  target_bitrate_ = target_bitrate;
  incoming_framerate_ = incoming_framerate;
  sum_incoming_framerate_ += incoming_framerate_;
  // Update the per_frame_bandwidth:
  // this is the per_frame_bw for the current/next ~1sec.
  per_frame_bandwidth_ = 0.0f;
  if (incoming_framerate_ > 0.0f) {
    per_frame_bandwidth_ = target_bitrate_ / incoming_framerate_;
  }
}