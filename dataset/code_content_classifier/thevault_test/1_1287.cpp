std::unique_ptr<H265SpsRangeExtensionParser::SpsRangeExtensionState>
H265SpsRangeExtensionParser::ParseSpsRangeExtension(const uint8_t* data,
                                                    size_t length) noexcept {
  std::vector<uint8_t> unpacked_buffer = UnescapeRbsp(data, length);
  rtc::BitBuffer bit_buffer(unpacked_buffer.data(), unpacked_buffer.size());
  return ParseSpsRangeExtension(&bit_buffer);
}