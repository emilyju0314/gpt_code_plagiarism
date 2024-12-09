static void decode_number_stream(size_t num_elements,
                                 iarchive& iarc,
                                 Fn callback) {
  uint64_t buf[MAX_INTEGERS_PER_BLOCK];
  while(num_elements > 0) {
    size_t buflen = std::min<size_t>(num_elements, MAX_INTEGERS_PER_BLOCK);
    frame_of_reference_decode_128(iarc, buflen, buf);
    for (size_t i = 0;i < buflen; ++i) {
      callback(flexible_type(buf[i]));
    }
    num_elements -= buflen;
  }
}