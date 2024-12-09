std::string
Gogo::function_asm_name(const std::string& go_name, const Package* package,
			const Type* rtype)
{
  std::string ret;
  if (rtype != NULL)
    ret = rtype->deref()->mangled_name(this);
  else if (package == NULL)
    ret = this->pkgpath_symbol();
  else
    ret = package->pkgpath_symbol();
  ret.push_back('.');
  // Check for special names that will break if we use
  // Gogo::unpack_hidden_name.
  if (Gogo::is_special_name(go_name))
    ret.append(go_name);
  else
    ret.append(Gogo::unpack_hidden_name(go_name));
  return go_encode_id(ret);
}