std::unique_ptr<H265Sps3dExtensionParser::Sps3dExtensionState>
H265Sps3dExtensionParser::ParseSps3dExtension(const uint8_t* data,
                                              size_t length) noexcept {
  std::vector<uint8_t> unpacked_buffer = UnescapeRbsp(data, length);
  rtc::BitBuffer bit_buffer(unpacked_buffer.data(), unpacked_buffer.size());
  return ParseSps3dExtension(&bit_buffer);
}