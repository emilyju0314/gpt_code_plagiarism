void utils::split (const std::string& str, const char delim, std::vector<std::string>& elems)
{
  elems.clear();
  std::stringstream ss (str);
  std::string item;

  while(getline(ss, item, delim)) {
    elems.push_back(item);
  }
}