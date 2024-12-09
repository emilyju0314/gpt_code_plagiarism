std::string
Gogo::thunk_name()
{
  static int thunk_count;
  char thunk_name[50];
  snprintf(thunk_name, sizeof thunk_name, "..thunk%d", thunk_count);
  ++thunk_count;
  std::string ret = this->pkgpath_symbol();
  return ret + thunk_name;
}