inline std::map<std::string, flexible_type> varmap_to_flexmap(const variant_map_type& map) {
  std::map<std::string, flexible_type> ret;
  for (const auto& kv : map) {
    if (kv.second.type() == typeid(flexible_type)) {
      ret[kv.first] = boost::get<flexible_type>(kv.second);
    }
  }
  return ret;
}