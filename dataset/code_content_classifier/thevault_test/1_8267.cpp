Statement*
Gogo::assign_with_write_barrier(Function* function, Block* enclosing,
				Statement_inserter* inserter, Expression* lhs,
				Expression* rhs, Location loc)
{
  if (function != NULL
      && ((function->pragmas() & GOPRAGMA_NOWRITEBARRIER) != 0
	  || (function->pragmas() & GOPRAGMA_NOWRITEBARRIERREC) != 0))
    go_error_at(loc, "write barrier prohibited");

  Type* type = lhs->type();
  go_assert(type->has_pointer());

  Expression* addr;
  if (lhs->unary_expression() != NULL
      && lhs->unary_expression()->op() == OPERATOR_MULT)
    addr = lhs->unary_expression()->operand();
  else
    {
      addr = Expression::make_unary(OPERATOR_AND, lhs, loc);
      addr->unary_expression()->set_does_not_escape();
    }
  Temporary_statement* lhs_temp = Statement::make_temporary(NULL, addr, loc);
  inserter->insert(lhs_temp);
  lhs = Expression::make_temporary_reference(lhs_temp, loc);

  if (!Type::are_identical(type, rhs->type(), false, NULL)
      && rhs->type()->interface_type() != NULL
      && !rhs->is_variable())
    {
      // May need a temporary for interface conversion.
      Temporary_statement* temp = Statement::make_temporary(NULL, rhs, loc);
      inserter->insert(temp);
      rhs = Expression::make_temporary_reference(temp, loc);
    }
  rhs = Expression::convert_for_assignment(this, type, rhs, loc);
  Temporary_statement* rhs_temp = NULL;
  if (!rhs->is_variable() && !rhs->is_constant())
    {
      rhs_temp = Statement::make_temporary(NULL, rhs, loc);
      inserter->insert(rhs_temp);
      rhs = Expression::make_temporary_reference(rhs_temp, loc);
    }

  Expression* indir =
      Expression::make_dereference(lhs, Expression::NIL_CHECK_DEFAULT, loc);
  Statement* assign = Statement::make_assignment(indir, rhs, loc);

  lhs = Expression::make_temporary_reference(lhs_temp, loc);
  if (rhs_temp != NULL)
    rhs = Expression::make_temporary_reference(rhs_temp, loc);

  Type* unsafe_ptr_type = Type::make_pointer_type(Type::make_void_type());
  lhs = Expression::make_unsafe_cast(unsafe_ptr_type, lhs, loc);

  Expression* call;
  switch (type->base()->classification())
    {
    default:
      go_unreachable();

    case Type::TYPE_ERROR:
      return assign;

    case Type::TYPE_POINTER:
    case Type::TYPE_FUNCTION:
    case Type::TYPE_MAP:
    case Type::TYPE_CHANNEL:
      // These types are all represented by a single pointer.
      call = Runtime::make_call(Runtime::WRITEBARRIERPTR, loc, 2, lhs, rhs);
      break;

    case Type::TYPE_STRING:
    case Type::TYPE_STRUCT:
    case Type::TYPE_ARRAY:
    case Type::TYPE_INTERFACE:
      {
	rhs = Expression::make_unary(OPERATOR_AND, rhs, loc);
	rhs->unary_expression()->set_does_not_escape();
	call = Runtime::make_call(Runtime::TYPEDMEMMOVE, loc, 3,
				  Expression::make_type_descriptor(type, loc),
				  lhs, rhs);
      }
      break;
    }

  return this->check_write_barrier(enclosing, assign,
				   Statement::make_statement(call, false));
}