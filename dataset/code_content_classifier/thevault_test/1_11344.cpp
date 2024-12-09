void decode_double(iarchive& iarc,
                   std::vector<flexible_type>& ret,
                   size_t num_undefined) {
  // we reserve one character so we can add new encoders as needed in the future
  char reserved = 0;
  iarc.read(&(reserved), sizeof(reserved));
  ASSERT_LT(reserved, 3);
  if (reserved == DOUBLE_RESERVED_FLAGS::LEGACY_ENCODING) {
    decode_double_legacy(iarc, ret, num_undefined);
    return;
  } else if (reserved == DOUBLE_RESERVED_FLAGS::INTEGER_ENCODING) {
    for (auto& i : ret) {
      if (i.get_type() == flex_type_enum::FLOAT) i.reset(flex_type_enum::INTEGER);
    }
    decode_number(iarc, ret, num_undefined);
    for (auto& i : ret) {
      if (i.get_type() == flex_type_enum::INTEGER) {
        i = (flex_float)(i.get<flex_int>());
      }
    }
    return;
  } 
}