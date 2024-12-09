void encode_double(block_info& info, 
                   oarchive& oarc, 
                   const std::vector<flexible_type>& data) {
  // we reserve one character so we can add new encoders as needed in the future
  char reserved = 0;
  bool safe_for_integer_code = true;
  for (size_t i = 0;i < data.size(); ++i) {
    if (data[i].get_type() == flex_type_enum::FLOAT) {
      flex_float val = data[i].get<flex_float>();
      flex_int int_val = (flex_int)val;
      flex_float new_float_val = int_val;
      if (new_float_val != val) {
        safe_for_integer_code = false;
        break;
      }
    }
  }
  if (safe_for_integer_code) {
    reserved = DOUBLE_RESERVED_FLAGS::INTEGER_ENCODING;
  } else {
    reserved = DOUBLE_RESERVED_FLAGS::LEGACY_ENCODING;
  }
  oarc.write(&(reserved), sizeof(reserved));
  if (reserved == DOUBLE_RESERVED_FLAGS::LEGACY_ENCODING) {
    encode_double_legacy(info, oarc, data);
    return;
  } else if (reserved == DOUBLE_RESERVED_FLAGS::INTEGER_ENCODING) {
    std::vector<flexible_type> copy = data;
    for (auto& i : copy) {
      if (i.get_type() == flex_type_enum::FLOAT) {
        i = (flex_int)(i.get<flex_float>());
      }
    }
    encode_number(info, oarc, copy);
    return;
  } 
}