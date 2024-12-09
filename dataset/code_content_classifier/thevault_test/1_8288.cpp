std::string
Type::mangled_name(Gogo* gogo) const
{
  std::string ret;

  // The do_mangled_name virtual function will set RET to the mangled
  // name before glue character mapping.
  this->do_mangled_name(gogo, &ret);

  // Type descriptor names and interface method table names use a ".."
  // before the mangled name of a type, so to avoid ambiguity the
  // mangled name must not start with 'u' or 'U' or a digit.
  go_assert((ret[0] < '0' || ret[0] > '9') && ret[0] != ' ');
  if (ret[0] == 'u' || ret[0] == 'U')
    ret = " " + ret;

  // Map glue characters as described above.

  // The mapping is only unambiguous if there is no .DIGIT in the
  // string, so check that.
  for (size_t i = ret.find('.');
       i != std::string::npos;
       i = ret.find('.', i + 1))
    {
      if (i + 1 < ret.size())
	{
	  char c = ret[i + 1];
	  go_assert(c < '0' || c > '9');
	}
    }

  // The order of these characters is the replacement code.
  const char * const replace = " *;,{}[]()";

  const size_t rlen = strlen(replace);
  char buf[2];
  buf[0] = '.';
  for (size_t ri = 0; ri < rlen; ++ri)
    {
      buf[1] = '0' + ri;
      while (true)
	{
	  size_t i = ret.find(replace[ri]);
	  if (i == std::string::npos)
	    break;
	  ret.replace(i, 1, buf, 2);
	}
    }

  return ret;
}