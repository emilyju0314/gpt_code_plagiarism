std::vector<char> XGetopt::decompose_shortopts(std::string const &shortopts) {
  Require(shortopts.size() > 0);
  std::vector<char> vso;
  for (size_t i = 0; i < shortopts.size(); ++i) {
    vso.push_back(shortopts[i]);
    if (i + 1 < shortopts.size() && shortopts[i + 1] == std::string(":")[0])
      this->vshortopts_hasarg[shortopts[i]] = true;
    else
      this->vshortopts_hasarg[shortopts[i]] = false;
  }
  Ensure(vso.size() > 0 && vso.size() <= shortopts.size());
  return vso;
}