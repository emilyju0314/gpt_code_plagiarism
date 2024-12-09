rtc::ByteBuffer* ParseRbsp(const uint8_t* bytes, size_t length) {
  // Copied from webrtc::H264SpsParser::Parse.
  rtc::ByteBuffer* rbsp_buffer = new rtc::ByteBuffer;
  for (size_t i = 0; i < length;) {
    if (length - i >= 3 && bytes[i] == 0 && bytes[i + 1] == 0 &&
        bytes[i + 2] == 3) {
      rbsp_buffer->WriteBytes(reinterpret_cast<const char*>(bytes) + i, 2);
      i += 3;
    } else {
      rbsp_buffer->WriteBytes(reinterpret_cast<const char*>(bytes) + i, 1);
      i++;
    }
  }
  return rbsp_buffer;
}