XGetopt::csmap XGetopt::store_longopts(csmap const &longopts_) {
  Require(longopts_.size() > 0);
  csmap retValue;
  for (auto const &it : longopts_) {
    char const key = it.first;
    std::string const value = it.second;
    if (value[value.size() - 1] == ':')
      retValue[key] = value.substr(0, value.size() - 1);
    else
      retValue[key] = value;
  }
  Ensure(retValue.size() == longopts_.size());
  return retValue;
}