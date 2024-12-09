inline std::map<std::string, variant_type> flexmap_to_varmap(const std::map<std::string, flexible_type>& map) {
  std::map<std::string, variant_type> ret;
  for (const auto& kv : map) {
    ret[kv.first] = (variant_type) kv.second; 
  }
  return ret;
}