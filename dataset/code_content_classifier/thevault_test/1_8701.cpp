std::string config_name_from_fname(std::string_view fname) {
  const auto last_slash  = fname.rfind('/');
  const auto last_dot    = fname.rfind('.');
  const auto config_name = fname.substr(last_slash + 1, last_dot - last_slash - 1);

  return std::string(config_name);
}