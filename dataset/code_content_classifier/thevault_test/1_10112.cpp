int32_t AcmSendTestOldApi::SendData(
    FrameType frame_type,
    uint8_t payload_type,
    uint32_t timestamp,
    const uint8_t* payload_data,
    size_t payload_len_bytes,
    const RTPFragmentationHeader* fragmentation) {
  // Store the packet locally.
  frame_type_ = frame_type;
  payload_type_ = payload_type;
  timestamp_ = timestamp;
  last_payload_vec_.assign(payload_data, payload_data + payload_len_bytes);
  assert(last_payload_vec_.size() == payload_len_bytes);
  data_to_send_ = true;
  return 0;
}