void
Named_type::append_mangled_type_name(Gogo* gogo, bool use_alias,
				     std::string* ret) const
{
  if (this->is_error_)
    return;
  if (this->is_alias_ && !use_alias)
    {
      if (this->seen_alias_)
	return;
      this->seen_alias_ = true;
      this->append_mangled_name(this->type_, gogo, ret);
      this->seen_alias_ = false;
      return;
    }
  Named_object* no = this->named_object_;
  std::string name;
  if (this->is_builtin())
    go_assert(this->in_function_ == NULL);
  else
    {
      if (this->in_function_ != NULL)
	{
	  const Typed_identifier* rcvr =
	    this->in_function_->func_value()->type()->receiver();
	  if (rcvr != NULL)
	    ret->append(rcvr->type()->deref()->mangled_name(gogo));
	  else if (this->in_function_->package() == NULL)
	    ret->append(gogo->pkgpath_symbol());
	  else
	    ret->append(this->in_function_->package()->pkgpath_symbol());
	  ret->push_back('.');
	  ret->append(Gogo::unpack_hidden_name(this->in_function_->name()));
	}
      else
	{
	  if (no->package() == NULL)
	    ret->append(gogo->pkgpath_symbol());
	  else
	    ret->append(no->package()->pkgpath_symbol());
	}
      ret->push_back('.');
    }

  ret->append(Gogo::unpack_hidden_name(no->name()));

  if (this->in_function_ != NULL && this->in_function_index_ > 0)
    {
      char buf[30];
      snprintf(buf, sizeof buf, "..i%u", this->in_function_index_);
      ret->append(buf);
    }
}