void
Gogo::specific_type_function_names(const Type* type, const Named_type* name,
				   std::string *hash_name,
				   std::string *equal_name)
{
  const Type* rtype = type;
  if (name != NULL)
    rtype = name;
  std::string tname = rtype->mangled_name(this);
  *hash_name = tname + "..hash";
  *equal_name = tname + "..eq";
}