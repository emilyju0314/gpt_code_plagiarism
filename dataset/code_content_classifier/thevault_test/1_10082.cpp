void VCMQmResolution::UpdateEncodedSize(size_t encoded_size) {
  frame_cnt_++;
  // Convert to Kbps.
  float encoded_size_kbits = 8.0f * static_cast<float>(encoded_size) / 1000.0f;

  // Update the buffer level:
  // Note this is not the actual encoder buffer level.
  // |buffer_level_| is reset to an initial value after SelectResolution is
  // called, and does not account for frame dropping by encoder or VCM.
  buffer_level_ += per_frame_bandwidth_ - encoded_size_kbits;

  // Counter for occurrences of low buffer level:
  // low/negative values means encoder is likely dropping frames.
  if (buffer_level_ <= kPercBufferThr * kInitBufferLevel * target_bitrate_) {
    low_buffer_cnt_++;
  }
}