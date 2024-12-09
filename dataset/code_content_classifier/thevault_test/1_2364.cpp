std::vector<char> XGetopt::decompose_longopts(csmap const &longopts_) {
  Require(longopts_.size() > 0);
  std::vector<char> vso;
  for (auto const &it : longopts_) {
    char const key = it.first;
    std::string const value = it.second;
    Insist(std::find(vso.begin(), vso.end(), key) == vso.end(),
           "You cannot use the same single character command line argument "
           "more than once.");
    vso.push_back(key);
    if (value[value.size() - 1] == ':')
      this->vshortopts_hasarg[key] = true;
    else
      this->vshortopts_hasarg[key] = false;
  }
  Ensure(vso.size() == longopts_.size());
  return vso;
}