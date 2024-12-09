void encode_number(block_info& info, 
                   oarchive& oarc, 
                   const std::vector<flexible_type>& data) {
  for (size_t i = 0;i < data.size(); ) {
    uint64_t encode_buf[MAX_INTEGERS_PER_BLOCK];
    size_t encode_buflen = 0;
    // collect a block of 128 integers
    while(i < data.size() && encode_buflen < MAX_INTEGERS_PER_BLOCK) {
      if (data[i].get_type() != flex_type_enum::UNDEFINED) {
        encode_buf[encode_buflen] = data[i].get<flex_int>();
        ++encode_buflen;
      }
      ++i;
    }
    if (encode_buflen == 0) break;
    //     logstream(LOG_INFO) << "Encoding ";
    //     for (size_t i = 0;i < encode_buflen; ++i) {
    //       logstream(LOG_INFO) << " " << encode_buf[i];
    //     }
    //     logstream(LOG_INFO) << std::endl;
    frame_of_reference_encode_128(encode_buf, encode_buflen, oarc);
  }
}