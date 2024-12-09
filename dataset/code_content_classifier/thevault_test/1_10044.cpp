bool H264BitstreamParser::ParseSpsNalu(const uint8_t* sps, size_t length) {
  // Reset SPS state.
  sps_ = SpsState();
  sps_parsed_ = false;
  // Parse out the SPS RBSP. It should be small, so it's ok that we create a
  // copy. We'll eventually write this back.
  rtc::scoped_ptr<rtc::ByteBuffer> sps_rbsp(
      ParseRbsp(sps + kNaluHeaderAndTypeSize, length - kNaluHeaderAndTypeSize));
  rtc::BitBuffer sps_parser(reinterpret_cast<const uint8_t*>(sps_rbsp->Data()),
                            sps_rbsp->Length());

  uint8_t byte_tmp;
  uint32_t golomb_tmp;
  uint32_t bits_tmp;

  // profile_idc: u(8).
  uint8_t profile_idc;
  RETURN_FALSE_ON_FAIL(sps_parser.ReadUInt8(&profile_idc));
  // constraint_set0_flag through constraint_set5_flag + reserved_zero_2bits
  // 1 bit each for the flags + 2 bits = 8 bits = 1 byte.
  RETURN_FALSE_ON_FAIL(sps_parser.ReadUInt8(&byte_tmp));
  // level_idc: u(8)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadUInt8(&byte_tmp));
  // seq_parameter_set_id: ue(v)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
  sps_.separate_colour_plane_flag = 0;
  // See if profile_idc has chroma format information.
  if (profile_idc == 100 || profile_idc == 110 || profile_idc == 122 ||
      profile_idc == 244 || profile_idc == 44 || profile_idc == 83 ||
      profile_idc == 86 || profile_idc == 118 || profile_idc == 128 ||
      profile_idc == 138 || profile_idc == 139 || profile_idc == 134) {
    // chroma_format_idc: ue(v)
    uint32_t chroma_format_idc;
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&chroma_format_idc));
    if (chroma_format_idc == 3) {
      // separate_colour_plane_flag: u(1)
      RETURN_FALSE_ON_FAIL(
          sps_parser.ReadBits(&sps_.separate_colour_plane_flag, 1));
    }
    // bit_depth_luma_minus8: ue(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
    // bit_depth_chroma_minus8: ue(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
    // qpprime_y_zero_transform_bypass_flag: u(1)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadBits(&bits_tmp, 1));
    // seq_scaling_matrix_present_flag: u(1)
    uint32_t seq_scaling_matrix_present_flag;
    RETURN_FALSE_ON_FAIL(
        sps_parser.ReadBits(&seq_scaling_matrix_present_flag, 1));
    if (seq_scaling_matrix_present_flag) {
      // seq_scaling_list_present_flags. Either 8 or 12, depending on
      // chroma_format_idc.
      uint32_t seq_scaling_list_present_flags;
      if (chroma_format_idc != 3) {
        RETURN_FALSE_ON_FAIL(
            sps_parser.ReadBits(&seq_scaling_list_present_flags, 8));
      } else {
        RETURN_FALSE_ON_FAIL(
            sps_parser.ReadBits(&seq_scaling_list_present_flags, 12));
      }
      // TODO(pbos): Support parsing scaling lists if they're seen in practice.
      RTC_CHECK(seq_scaling_list_present_flags == 0)
          << "SPS contains scaling lists, which are unsupported.";
    }
  }
  // log2_max_frame_num_minus4: ue(v)
  RETURN_FALSE_ON_FAIL(
      sps_parser.ReadExponentialGolomb(&sps_.log2_max_frame_num_minus4));
  // pic_order_cnt_type: ue(v)
  RETURN_FALSE_ON_FAIL(
      sps_parser.ReadExponentialGolomb(&sps_.pic_order_cnt_type));

  if (sps_.pic_order_cnt_type == 0) {
    // log2_max_pic_order_cnt_lsb_minus4: ue(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(
        &sps_.log2_max_pic_order_cnt_lsb_minus4));
  } else if (sps_.pic_order_cnt_type == 1) {
    // delta_pic_order_always_zero_flag: u(1)
    RETURN_FALSE_ON_FAIL(
        sps_parser.ReadBits(&sps_.delta_pic_order_always_zero_flag, 1));
    // offset_for_non_ref_pic: se(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
    // offset_for_top_to_bottom_field: se(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
    uint32_t num_ref_frames_in_pic_order_cnt_cycle;
    // num_ref_frames_in_pic_order_cnt_cycle: ue(v)
    RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(
        &num_ref_frames_in_pic_order_cnt_cycle));
    for (uint32_t i = 0; i < num_ref_frames_in_pic_order_cnt_cycle; i++) {
      // offset_for_ref_frame[i]: se(v)
      RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
    }
  }
  // max_num_ref_frames: ue(v)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
  // gaps_in_frame_num_value_allowed_flag: u(1)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadBits(&bits_tmp, 1));
  // pic_width_in_mbs_minus1: ue(v)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
  // pic_height_in_map_units_minus1: ue(v)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadExponentialGolomb(&golomb_tmp));
  // frame_mbs_only_flag: u(1)
  RETURN_FALSE_ON_FAIL(sps_parser.ReadBits(&sps_.frame_mbs_only_flag, 1));
  sps_parsed_ = true;
  return true;
}