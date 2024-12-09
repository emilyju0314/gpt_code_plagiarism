bool
go_id_needs_encoding(const std::string& str)
{
  for (std::string::const_iterator p = str.begin();
       p != str.end();
       ++p)
    if (char_needs_encoding(*p))
      return true;
  return false;
}