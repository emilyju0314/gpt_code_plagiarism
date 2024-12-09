int
Write_barriers::statement(Block* block, size_t* pindex, Statement* s)
{
  switch (s->classification())
    {
    default:
      break;

    case Statement::STATEMENT_VARIABLE_DECLARATION:
      {
	Variable_declaration_statement* vds =
	  s->variable_declaration_statement();
	Named_object* no = vds->var();
	Variable* var = no->var_value();

	// We may need to emit a write barrier for the initialization
	// of the variable.

	// Nothing to do for a variable with no initializer.
	Expression* init = var->init();
	if (init == NULL)
	  break;

	// Nothing to do if the variable is not in the heap.  Only
	// local variables get declaration statements, and local
	// variables on the stack do not require write barriers.
	if (!var->is_in_heap())
	  break;

	// Nothing to do if the variable does not contain any pointers.
	if (!var->type()->has_pointer())
	  break;

	// Nothing to do for a type that can not be in the heap, or a
	// pointer to a type that can not be in the heap.
	if (!var->type()->in_heap())
	  break;
	if (var->type()->points_to() != NULL
	    && !var->type()->points_to()->in_heap())
	  break;

	// Otherwise initialize the variable with a write barrier.

	Function* function = this->function_;
	Location loc = init->location();
	Statement_inserter inserter(block, pindex);

	// Insert the variable declaration statement with no
	// initializer, so that the variable exists.
	var->clear_init();
	inserter.insert(s);

	// Create a statement that initializes the variable with a
	// write barrier.
	Expression* ref = Expression::make_var_reference(no, loc);
	Statement* assign = this->gogo_->assign_with_write_barrier(function,
								   block,
								   &inserter,
								   ref, init,
								   loc);

	// Replace the old variable declaration statement with the new
	// initialization.
	block->replace_statement(*pindex, assign);
      }
      break;

    case Statement::STATEMENT_ASSIGNMENT:
      {
	Assignment_statement* as = s->assignment_statement();
	Expression* lhs = as->lhs();
	Expression* rhs = as->rhs();

	// We may need to emit a write barrier for the assignment.

	if (!this->gogo_->assign_needs_write_barrier(lhs))
	  break;

	// Change the assignment to use a write barrier.
	Function* function = this->function_;
	Location loc = as->location();
	Statement_inserter inserter = Statement_inserter(block, pindex);
	Statement* assign = this->gogo_->assign_with_write_barrier(function,
								   block,
								   &inserter,
								   lhs, rhs,
								   loc);
	block->replace_statement(*pindex, assign);
      }
      break;
    }

  return TRAVERSE_CONTINUE;
}