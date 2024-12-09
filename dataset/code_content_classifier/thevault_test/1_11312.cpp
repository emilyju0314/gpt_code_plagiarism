static void decode_double_stream_legacy(size_t num_elements,
                                 iarchive& iarc,
                                 Fn callback) {
  uint64_t buf[MAX_INTEGERS_PER_BLOCK];
  while(num_elements > 0) {
    size_t buflen = std::min<size_t>(num_elements, MAX_INTEGERS_PER_BLOCK);
    frame_of_reference_decode_128(iarc, buflen, buf);
    for (size_t i = 0;i < buflen; ++i) {
      size_t intval = (buf[i] >> 1) | (buf[i] << 63);
      // make a double flexible_type
      flexible_type ret(0.0);
      ret.mutable_get<flex_int>() = intval;
      callback(ret);
    }
    num_elements -= buflen;
  }
}