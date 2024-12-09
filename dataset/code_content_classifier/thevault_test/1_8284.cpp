std::string
Gogo::recover_thunk_name(const std::string& name, const Type* rtype)
{
  std::string ret;
  if (rtype != NULL)
    {
      ret = rtype->mangled_name(this);
      ret.append(1, '.');
    }
  if (Gogo::is_special_name(name))
    ret.append(name);
  else
    ret.append(Gogo::unpack_hidden_name(name));
  ret.append("..r");
  return ret;
}