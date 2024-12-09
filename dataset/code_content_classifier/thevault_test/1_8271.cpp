std::string
go_encode_id(const std::string &id)
{
  if (Lex::is_invalid_identifier(id))
    {
      go_assert(saw_errors());
      return id;
    }

  // The encoding is only unambiguous if the input string does not
  // contain ..u or ..U.
  go_assert(id.find("..u") == std::string::npos);
  go_assert(id.find("..U") == std::string::npos);

  std::string ret;
  const char* p = id.c_str();
  const char* pend = p + id.length();

  // A leading ".0" is a space introduced before a mangled type name
  // that starts with a 'u' or 'U', to avoid confusion with the
  // mangling used here.  We don't need a leading ".0", and we don't
  // want symbols that start with '.', so remove it.
  if (p[0] == '.' && p[1] == '0')
    p += 2;

  while (p < pend)
    {
      unsigned int c;
      size_t len = fetch_utf8_char(p, &c);
      if (len == 1)
	{
	  // At this point we should only be seeing alphanumerics or
	  // underscore or dot.
	  go_assert(!char_needs_encoding(c));
	  ret += c;
	}
      else
	{
	  char buf[16];
	  if (c < 0x10000)
	    snprintf(buf, sizeof buf, "..u%04x", c);
	  else
	    snprintf(buf, sizeof buf, "..U%08x", c);

	  // We don't want a symbol to start with '.', so add a prefix
	  // if needed.
	  if (ret.empty())
	    ret += '_';

	  ret += buf;
	}
      p += len;
    }
  return ret;
}