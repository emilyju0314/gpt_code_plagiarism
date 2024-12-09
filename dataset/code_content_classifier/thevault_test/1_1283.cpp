std::unique_ptr<H265SubLayerHrdParametersParser::SubLayerHrdParametersState>
H265SubLayerHrdParametersParser::ParseSubLayerHrdParameters(
    const uint8_t* data, size_t length, uint32_t subLayerId, uint32_t CpbCnt,
    uint32_t sub_pic_hrd_params_present_flag) noexcept {
  std::vector<uint8_t> unpacked_buffer = UnescapeRbsp(data, length);
  rtc::BitBuffer bit_buffer(unpacked_buffer.data(), unpacked_buffer.size());
  return ParseSubLayerHrdParameters(&bit_buffer, subLayerId, CpbCnt,
                                    sub_pic_hrd_params_present_flag);
}