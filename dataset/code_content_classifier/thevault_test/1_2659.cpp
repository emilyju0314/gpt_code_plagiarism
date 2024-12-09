bool
DataFileEngineCfg::
get_names(std::list<std::string>& names, const std::string& scope) const
{
  if (scope.empty()) {
    // Return all variables
    rc_data* data = data_;
    names.clear();
    while (data && data->param) {
      names.push_back(data->param);
      data = data->next;
    }
  }
  else if (scope == DATA_FILE_GLOBAL_SCOPE) {
    WARNING << "CFG files do not have the concept of global attributes";
    ENDWARNING;
    return 0;
  }
  else {
    // Return variables prefixed by contents of "scope"
    rc_data* data = data_;
    std::string param;
    std::string scope_dot = scope + ".";
    size_t scope_len = scope_dot.size();
    names.clear();
    while (data && data->param) {
      param = data->param;
      if (param.size() > scope_len
	  && param.substr(0,scope_len) == scope_dot) {
	names.push_back(param.substr(scope_len, std::string::npos));
      }
      data = data->next;
    }
  }
  
  return true;
}