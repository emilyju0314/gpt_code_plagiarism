std::unique_ptr<H265SpsSccExtensionParser::SpsSccExtensionState>
H265SpsSccExtensionParser::ParseSpsSccExtension(
    const uint8_t* data, size_t length, uint32_t chroma_format_idc,
    uint32_t bit_depth_luma_minus8, uint32_t bit_depth_chroma_minus8) noexcept {
  std::vector<uint8_t> unpacked_buffer = UnescapeRbsp(data, length);
  rtc::BitBuffer bit_buffer(unpacked_buffer.data(), unpacked_buffer.size());
  return ParseSpsSccExtension(&bit_buffer, chroma_format_idc,
                              bit_depth_luma_minus8, bit_depth_chroma_minus8);
}