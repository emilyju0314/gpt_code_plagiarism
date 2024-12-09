std::string
go_mangle_struct_tag(const std::string& tag)
{
  std::string ret;
  const char* p = tag.c_str();
  const char* pend = p + tag.length();
  while (p < pend)
    {
      unsigned int c;
      size_t len = fetch_utf8_char(p, &c);
      if (len > 1)
	ret.append(p, len);
      else if (!char_needs_encoding(c) && c != '.')
	ret += c;
      else
	{
	  char buf[16];
	  snprintf(buf, sizeof buf, ".x%02x", c);
	  ret += buf;
	}
      p += len;
    }
  return ret;
}