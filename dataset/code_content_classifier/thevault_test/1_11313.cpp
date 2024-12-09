static void decode_double_stream(size_t num_elements,
                                 iarchive& iarc,
                                 Fn callback) {
  // we reserve one character so we can add new encoders as needed in the future
  char reserved = 0;
  iarc.read(&(reserved), sizeof(reserved));
  ASSERT_LT(reserved, 3);
  if (reserved == DOUBLE_RESERVED_FLAGS::LEGACY_ENCODING) {
    decode_double_stream_legacy(num_elements, iarc, callback);
    return;
  } else if (reserved == DOUBLE_RESERVED_FLAGS::INTEGER_ENCODING) {
    decode_number_stream(num_elements, iarc, 
                         [=](const flexible_type& val) {
                           flex_float ret = flex_float(val.get<flex_int>());
                           callback(ret);
                         });
  } 
}