ExprStringType CCalcDlg::without_parens(const ExprStringType &ss)
{
	int len = ss.GetLength();

	if (len > 0 && ss[0] == '(')
	{
		while (--len > 0)
		{
			if (ss[len] == ')')
				return ss.Mid(1, len-1);
			else if (ss[len] != ' ')
				break;
		}
	}
	return ss;
}