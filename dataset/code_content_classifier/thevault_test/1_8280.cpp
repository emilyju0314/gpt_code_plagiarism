std::string
Gogo::init_function_name()
{
  static int init_count;
  char buf[30];
  snprintf(buf, sizeof buf, "..init%d", init_count);
  ++init_count;
  std::string ret = this->pkgpath_symbol();
  return ret + buf;
}