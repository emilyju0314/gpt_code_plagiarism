void encode_double_legacy(block_info& info, 
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
    // perform a left rotate on all the numbers.
    // Basically, doubles are stored as sign-and-magnitude. This means
    // that -1.0 looks *very* different from -1. 
    for (size_t j = 0;j < encode_buflen; ++j) {
      encode_buf[j] = (encode_buf[j] << 1) | (encode_buf[j] >> 63);
    }
    frame_of_reference_encode_128(encode_buf, encode_buflen, oarc);
  }
}