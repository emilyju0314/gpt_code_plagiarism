void decode_double_legacy(iarchive& iarc,
                   std::vector<flexible_type>& ret,
                   size_t num_undefined) {
  uint64_t buf[MAX_INTEGERS_PER_BLOCK];
  size_t bufstart = 0;
  size_t buflen = 0;
  size_t num_values_to_read = ret.size() - num_undefined;

  for (size_t i = 0;i < ret.size(); ++i) {
    if (ret[i].get_type() != flex_type_enum::UNDEFINED) {
      if (bufstart < buflen) {
        ret[i].mutable_get<flex_int>() = buf[bufstart];
        ++bufstart;
        --num_values_to_read;
      } else {
        buflen = std::min<size_t>(num_values_to_read, MAX_INTEGERS_PER_BLOCK);
        // decode a new block of 128 integers
        frame_of_reference_decode_128(iarc, buflen, buf);
        // right rotate
        for (size_t j = 0;j < buflen ; ++j) {
          buf[j] = (buf[j] >> 1) | (buf[j] << 63);
        }
        bufstart = 0;
        ret[i].mutable_get<flex_int>() = buf[bufstart];
        ++bufstart;
        --num_values_to_read;
      }
    }
  }
}