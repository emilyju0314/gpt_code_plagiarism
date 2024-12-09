bool
Gogo::assign_needs_write_barrier(Expression* lhs)
{
  // Nothing to do if the variable does not contain any pointers.
  if (!lhs->type()->has_pointer())
    return false;

  // An assignment to a field is handled like an assignment to the
  // struct.
  while (true)
    {
      // Nothing to do for a type that can not be in the heap, or a
      // pointer to a type that can not be in the heap.  We check this
      // at each level of a struct.
      if (!lhs->type()->in_heap())
	return false;
      if (lhs->type()->points_to() != NULL
	  && !lhs->type()->points_to()->in_heap())
	return false;

      Field_reference_expression* fre = lhs->field_reference_expression();
      if (fre == NULL)
	break;
      lhs = fre->expr();
    }

  // Nothing to do for an assignment to a temporary.
  if (lhs->temporary_reference_expression() != NULL)
    return false;

  // Nothing to do for an assignment to a sink.
  if (lhs->is_sink_expression())
    return false;

  // Nothing to do for an assignment to a local variable that is not
  // on the heap.
  Var_expression* ve = lhs->var_expression();
  if (ve != NULL)
    {
      Named_object* no = ve->named_object();
      if (no->is_variable())
	{
	  Variable* var = no->var_value();
	  if (!var->is_global() && !var->is_in_heap())
	    return false;
	}
      else if (no->is_result_variable())
	{
	  Result_variable* rvar = no->result_var_value();
	  if (!rvar->is_in_heap())
	    return false;
	}
    }

  // For a struct assignment, we don't need a write barrier if all the
  // pointer types can not be in the heap.
  Struct_type* st = lhs->type()->struct_type();
  if (st != NULL)
    {
      bool in_heap = false;
      const Struct_field_list* fields = st->fields();
      for (Struct_field_list::const_iterator p = fields->begin();
	   p != fields->end();
	   p++)
	{
	  Type* ft = p->type();
	  if (!ft->has_pointer())
	    continue;
	  if (!ft->in_heap())
	    continue;
	  if (ft->points_to() != NULL && !ft->points_to()->in_heap())
	    continue;
	  in_heap = true;
	  break;
	}
      if (!in_heap)
	return false;
    }

  // Write barrier needed in other cases.
  return true;
}