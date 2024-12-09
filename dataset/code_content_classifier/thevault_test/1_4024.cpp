bool vcard::is_key(const std::string& key, const std::string& expected)
{
  auto ikey = key.begin();
  for (auto iexp = expected.begin();
       iexp != expected.end();
       iexp++, ikey++)
  {
    if (ikey == key.end()) return false;
    if (std::toupper(*iexp) != std::toupper(*ikey)) return false;
  }

  if (ikey != key.end() &&
      *ikey != ':' &&
      *ikey != ';') {
    return false;
  }

  return true;
}