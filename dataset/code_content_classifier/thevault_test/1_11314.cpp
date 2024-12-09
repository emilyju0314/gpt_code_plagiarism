static void decode_string_stream(size_t num_elements,
                                 iarchive& iarc,
                                 Fn callback) {
  bool use_dictionary_encoding = false;
  std::vector<flexible_type> idx_values;
  idx_values.resize(num_elements, flexible_type(flex_type_enum::INTEGER));
  iarc >> use_dictionary_encoding;
  if (use_dictionary_encoding) {
    uint64_t num_values;
    std::vector<flexible_type> str_values;
    variable_decode(iarc, num_values);
    str_values.resize(num_values);
    for (auto& str: str_values) {
      std::string new_str;
      uint64_t str_len;
      variable_decode(iarc, str_len);
      new_str.resize(str_len);
      iarc.read(&(new_str[0]), str_len);
      str = std::move(new_str);
    }
    decode_number(iarc, idx_values, 0);
    for (size_t i = 0;i < num_elements; ++i) {
      callback(str_values[idx_values[i].get<flex_int>()]);
    }
  } else {
    // get all the lengths
    decode_number(iarc, idx_values, 0);
    flexible_type ret(flex_type_enum::STRING);
    for (size_t i = 0;i < num_elements; ++i) {
      size_t str_len = idx_values[i].get<flex_int>();
      ret.mutable_get<std::string>().resize(str_len);
      iarc.read(&(ret.mutable_get<std::string>()[0]), str_len);
      callback(ret);
    }
  }
}