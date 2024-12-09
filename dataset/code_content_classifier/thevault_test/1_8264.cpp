int
Write_barriers::variable(Named_object* no)
{
  // We handle local variables in the variable declaration statement.
  // We only have to handle global variables here.
  if (!no->is_variable())
    return TRAVERSE_CONTINUE;
  Variable* var = no->var_value();
  if (!var->is_global())
    return TRAVERSE_CONTINUE;

  // Nothing to do if there is no initializer.
  Expression* init = var->init();
  if (init == NULL)
    return TRAVERSE_CONTINUE;

  // Nothing to do for variables that do not contain any pointers.
  if (!var->type()->has_pointer())
    return TRAVERSE_CONTINUE;

  // Nothing to do if the initializer is static.
  init = Expression::make_cast(var->type(), init, var->location());
  if (!var->has_pre_init() && init->is_static_initializer())
    return TRAVERSE_CONTINUE;

  // Nothing to do for a type that can not be in the heap, or a
  // pointer to a type that can not be in the heap.
  if (!var->type()->in_heap())
    return TRAVERSE_CONTINUE;
  if (var->type()->points_to() != NULL && !var->type()->points_to()->in_heap())
    return TRAVERSE_CONTINUE;

  // Otherwise change the initializer into a pre_init assignment
  // statement with a write barrier.

  // We can't check for a dependency of the variable on itself after
  // we make this change, because the preinit statement will always
  // depend on the variable (since it assigns to it).  So check for a
  // self-dependency now.
  this->gogo_->check_self_dep(no);

  // Replace the initializer.
  Location loc = init->location();
  Expression* ref = Expression::make_var_reference(no, loc);

  Statement_inserter inserter(this->gogo_, var);
  Statement* s = this->gogo_->assign_with_write_barrier(NULL, NULL, &inserter,
							ref, init, loc);

  var->add_preinit_statement(this->gogo_, s);
  var->clear_init();

  return TRAVERSE_CONTINUE;
}