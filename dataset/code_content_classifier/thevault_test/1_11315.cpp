static void decode_vector_stream(size_t num_elements,
                                 iarchive& iarc,
                                 Fn callback,
                                 bool new_format) {
  // we reserve one character so we can add new encoders as needed in the future
  if (new_format) {
    char reserved = 0;
    iarc.read(&(reserved), sizeof(reserved));
  }
  // decode the length of each vector
  std::vector<flexible_type> lengths(num_elements);
  decode_number(iarc, lengths, 0);
  size_t total_num_values = 0;
  for (const flexible_type& length : lengths) {
    total_num_values += length.get<flex_int>();
  }

  // decode the values
  std::vector<flexible_type> values(total_num_values);
  if (new_format) {
    decode_double(iarc, values, 0);
  } else {
    decode_double_legacy(iarc, values, 0);
  }

  size_t length_ctr = 0;
  size_t value_ctr = 0;
  flexible_type ret(flex_type_enum::VECTOR);
  for (size_t i = 0 ;i < num_elements; ++i) {
    flex_vec& output_vec = ret.mutable_get<flex_vec>();
    // resize this to the appropriate length
    output_vec.resize(lengths[length_ctr].get<flex_int>());
    ++length_ctr;
    // fill in the value
    for(size_t j = 0; j < output_vec.size(); ++j) {
      output_vec[j] = values[value_ctr].get<flex_float>();
      ++value_ctr;
    }
    callback(ret);
  }
}