void FuzzAudioDecoder(const uint8_t* data,
                      size_t size,
                      AudioDecoder* decoder,
                      int sample_rate_hz,
                      size_t max_decoded_bytes,
                      int16_t* decoded) {
  const uint8_t* data_ptr = data;
  size_t remaining_size = size;
  size_t packet_len = PacketSizeFromTwoBytes(data_ptr, remaining_size);
  while (packet_len != 0 && packet_len <= remaining_size - 2) {
    data_ptr += 2;
    remaining_size -= 2;
    AudioDecoder::SpeechType speech_type;
    decoder->Decode(data_ptr, packet_len, sample_rate_hz, max_decoded_bytes,
                    decoded, &speech_type);
    data_ptr += packet_len;
    remaining_size -= packet_len;
    packet_len = PacketSizeFromTwoBytes(data_ptr, remaining_size);
  }
}