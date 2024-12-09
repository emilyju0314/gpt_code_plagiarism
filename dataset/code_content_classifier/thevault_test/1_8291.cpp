std::string
Gogo::type_descriptor_name(Type* type, Named_type* nt)
{
  // The type descriptor symbol for the unsafe.Pointer type is defined
  // in libgo/runtime/go-unsafe-pointer.c, so just use a reference to
  // that symbol for all unsafe pointer types.
  if (type->is_unsafe_pointer_type())
    return "unsafe.Pointer..d";

  if (nt == NULL)
    return "type.." + type->mangled_name(this);

  std::string ret;
  Named_object* no = nt->named_object();
  unsigned int index;
  const Named_object* in_function = nt->in_function(&index);
  if (nt->is_builtin())
    go_assert(in_function == NULL);
  else
    {
      if (in_function != NULL)
	{
	  const Typed_identifier* rcvr =
	    in_function->func_value()->type()->receiver();
	  if (rcvr != NULL)
	    ret.append(rcvr->type()->deref()->mangled_name(this));
	  else if (in_function->package() == NULL)
	    ret.append(this->pkgpath_symbol());
	  else
	    ret.append(in_function->package()->pkgpath_symbol());
	  ret.push_back('.');
	  ret.append(Gogo::unpack_hidden_name(in_function->name()));
	  ret.push_back('.');
	}

      if (no->package() == NULL)
	ret.append(this->pkgpath_symbol());
      else
	ret.append(no->package()->pkgpath_symbol());
      ret.push_back('.');
    }

  ret.append(Gogo::mangle_possibly_hidden_name(no->name()));

  if (in_function != NULL && index > 0)
    {
      char buf[30];
      snprintf(buf, sizeof buf, "..i%u", index);
      ret.append(buf);
    }

  ret.append("..d");

  return ret;
}