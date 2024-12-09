static void encode_string(block_info& info, 
                          oarchive& oarc, 
                          const std::vector<flexible_type>& data) {
  bool use_dictionary_encoding = true;
  std::unordered_map<std::string, size_t> unique_values;
  std::vector<flexible_type> idx_values;
  std::vector<std::string> str_values;
  idx_values.resize(data.size(), flexible_type(flex_type_enum::INTEGER));
  size_t idxctr = 0;
  for (size_t i = 0;i < data.size(); ++i) {
    if (data[i].get_type() != flex_type_enum::UNDEFINED) {
      auto iter = unique_values.find(data[i].get<std::string>());
      if (iter != unique_values.end()) {
        idx_values[idxctr++].mutable_get<flex_int>() = iter->second;
      } else {
        // if we have too many unique values, fail.
        if (unique_values.size() >= 64) {
          use_dictionary_encoding = false;
          break;
        }
        size_t newidx = unique_values.size();
        unique_values[data[i].get<std::string>()] = newidx;
        str_values.push_back(data[i].get<std::string>());
        idx_values[idxctr++].mutable_get<flex_int>() = newidx;
      }
    }
  }
  oarc << use_dictionary_encoding;
  if (use_dictionary_encoding) {
    idx_values.resize(idxctr);

    variable_encode(oarc, str_values.size());
    for (auto& str: str_values) {
      variable_encode(oarc, str.length());
      oarc.write(str.c_str(), str.length());
    }
    encode_number(info, oarc, idx_values);
  } else {
    // encode all the lengths 
    idxctr = 0;
    for (auto& f: data) {
      if (f.get_type() != flex_type_enum::UNDEFINED) {
        idx_values[idxctr++].mutable_get<flex_int>() = f.get<std::string>().length();
      }
    }
    idx_values.resize(idxctr);
    encode_number(info, oarc, idx_values);
    for (auto& f: data) {
      if (f.get_type() != flex_type_enum::UNDEFINED) {
        oarc.write(f.get<std::string>().c_str(), f.get<flex_string>().length());
      }
    }
  }
}