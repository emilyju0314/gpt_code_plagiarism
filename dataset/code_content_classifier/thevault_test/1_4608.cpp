const char *Tensor_String(Tensor a) {
  std::stringstream ss;
  ss << *a;
  std::string s = ss.str();
  char *r = new char[s.size() + 1];
  snprintf(r, s.size() + 1, "%s", s.c_str());
  return r;
}