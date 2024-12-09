static void encode_vector(block_info& info, 
                          oarchive& oarc, 
                          const std::vector<flexible_type>& data) {
  char reserved = VECTOR_RESERVED_FLAGS::NEW_ENCODING;
  oarc.write(&(reserved), sizeof(reserved));
  // length of each vector
  std::vector<flexible_type> lengths;
  // values of all the vectors concatted together
  std::vector<flexible_type> values;

  for (size_t i = 0;i < data.size(); ++i) {
    if (data[i].get_type() != flex_type_enum::UNDEFINED) {
      const flex_vec& vals = data[i].get<flex_vec>();
      lengths.push_back(vals.size());
      for (const double d: vals) {
        values.push_back(d);
      }
    }
  }
  encode_number(info, oarc, lengths);
  encode_double(info, oarc, values);
}