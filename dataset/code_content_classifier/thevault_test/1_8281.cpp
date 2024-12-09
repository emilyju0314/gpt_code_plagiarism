std::string
Gogo::nested_function_name(Named_object* enclosing)
{
  std::string prefix;
  unsigned int index;
  if (enclosing == NULL)
    {
      // A function literal at top level, as in
      // var f = func() {}
      static unsigned int toplevel_index;
      ++toplevel_index;
      index = toplevel_index;
      prefix = ".go";
    }
  else
    {
      while (true)
	{
	  Named_object* parent = enclosing->func_value()->enclosing();
	  if (parent == NULL)
	    break;
	  enclosing = parent;
	}
      const Typed_identifier* rcvr =
	enclosing->func_value()->type()->receiver();
      if (rcvr != NULL)
	{
	  prefix = rcvr->type()->mangled_name(this);
	  prefix.push_back('.');
	}
      prefix.append(Gogo::unpack_hidden_name(enclosing->name()));
      index = enclosing->func_value()->next_nested_function_index();
    }
  char buf[30];
  snprintf(buf, sizeof buf, "..func%u", index);
  return prefix + buf;
}