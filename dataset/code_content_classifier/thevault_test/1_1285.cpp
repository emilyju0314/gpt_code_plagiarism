std::unique_ptr<H265RtpFuParser::RtpFuState> H265RtpFuParser::ParseRtpFu(
    const uint8_t* data, size_t length,
    struct H265BitstreamParserState* bitstream_parser_state) noexcept {
  std::vector<uint8_t> unpacked_buffer = UnescapeRbsp(data, length);
  rtc::BitBuffer bit_buffer(unpacked_buffer.data(), unpacked_buffer.size());
  return ParseRtpFu(&bit_buffer, bitstream_parser_state);
}