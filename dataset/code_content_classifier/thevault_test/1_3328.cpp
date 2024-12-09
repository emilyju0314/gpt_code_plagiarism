ExprStringType CCalcDlg::inc_right_operand(const ExprStringType &expr)
{
	// First get the location of the right operand  in the string
	int pos = expr.GetLength() - 1;
	ASSERT(pos > 0 && expr[pos] == ')');
	pos--;
	while (isalnum(expr[pos]))
		pos--;
	++pos;     // move to first digit
	int replace_pos = pos;    // where we add the new value

	// Workout what radix to use
	int radix = orig_radix_;       // default to current expression radix
	if (expr[pos] == '0')
	{
		++pos;
		radix = 8;
		if (expr[pos] == 'x' || expr[pos] == 'X')
		{
			++pos;
			radix = 16;
		}
	}

	// Get the current value of the right operand
#ifdef UNICODE_TYPE_STRING
	int operand = wcstol((const wchar_t *)expr + pos, NULL, radix);
#else
	int operand = strtol((const char *)expr + pos, NULL, radix);
#endif
	// Re-create the expression string with incremented operand
	ExprStringType retval;
	retval.Format(EXPRSTR("%.*s%s)"), replace_pos, expr, int_as_string(operand + 1));
	return retval;
}