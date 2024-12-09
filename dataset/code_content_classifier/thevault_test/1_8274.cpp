std::string
Gogo::function_descriptor_name(Named_object* no)
{
  if (no->is_function() && !no->func_value()->asm_name().empty())
    return no->func_value()->asm_name() + "..f";
  else if (no->is_function_declaration()
	   && !no->func_declaration_value()->asm_name().empty())
    return no->func_declaration_value()->asm_name() + "..f";
  std::string ret = this->function_asm_name(no->name(), no->package(), NULL);
  ret.append("..f");
  return ret;
}