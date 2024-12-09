std::string normalize_path(std::string prefix) {
  boost::algorithm::trim(prefix); 
  if (prefix.length() == 0) return "/";
  else if (prefix[prefix.length() - 1] != '/') return prefix + "/";
  else return prefix;
}