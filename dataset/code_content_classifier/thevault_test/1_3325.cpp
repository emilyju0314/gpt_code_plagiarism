ExprStringType CCalcDlg::get_expr(bool no_paren /* = false */)
{
	ExprStringType retval;

	switch (op_)
	{
	case binop_none:
		if (state_ < CALCINTEXPR || right_[0] == '(' && right_[right_.GetLength()-1] == ')')
			retval = right_;
		else
			retval.Format(EXPRSTR("(%s)"), (const wchar_t *)right_);
		break;
	case binop_add:
		retval.Format(EXPRSTR("(%s + %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_subtract:
		retval.Format(EXPRSTR("(%s - %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_multiply:
		retval.Format(EXPRSTR("(%s * %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_divide:
		retval.Format(EXPRSTR("(%s / %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_mod:
		retval.Format(EXPRSTR("(%s %% %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_pow:
		retval.Format(EXPRSTR("pow(%s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_gtr:
	case binop_gtr_old:
		retval.Format(EXPRSTR("max(%s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_less:
	case binop_less_old:
		retval.Format(EXPRSTR("min(%s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_rol:
		retval.Format(EXPRSTR("rol(%s, %s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_, bits_as_string());
		break;
	case binop_ror:
		retval.Format(EXPRSTR("ror(%s, %s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_, bits_as_string());
		break;
	case binop_lsl:
		retval.Format(EXPRSTR("(%s << %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_lsr:
		retval.Format(EXPRSTR("(%s >> %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_asr:
		retval.Format(EXPRSTR("asr(%s, %s, %s)"), (const wchar_t *)left_, (const wchar_t *)right_, bits_as_string());
		break;

	case binop_and:
		retval.Format(EXPRSTR("(%s & %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_or:
		retval.Format(EXPRSTR("(%s | %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;
	case binop_xor:
		retval.Format(EXPRSTR("(%s ^ %s)"), (const wchar_t *)left_, (const wchar_t *)right_);
		break;

	default:
		ASSERT(0);
		break;
	}

	int len = retval.GetLength();
	if (no_paren)
		return without_parens(retval);
	else
		return retval;
}