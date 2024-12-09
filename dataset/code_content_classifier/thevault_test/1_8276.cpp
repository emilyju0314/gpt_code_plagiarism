std::string
Gogo::global_var_asm_name(const std::string& go_name, const Package* package)
{
  std::string ret;
  if (package == NULL)
    ret = this->pkgpath_symbol();
  else
    ret = package->pkgpath_symbol();
  ret.append(1, '.');
  ret.append(Gogo::unpack_hidden_name(go_name));
  return go_encode_id(ret);
}