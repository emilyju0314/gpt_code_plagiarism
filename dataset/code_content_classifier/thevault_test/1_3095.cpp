void CFindSheet::NewSearch(LPCTSTR ss)
{
	if (strlen(ss) == 0)
		return;
	else if (ss[0] == '~')
	{
		SetMatchCase(FALSE);
		NewText(ss+1);
	}
	else if (ss[0] == '=')
	{
		SetMatchCase(TRUE);
		NewText(ss+1);
	}
	else
	{
		// Must be a hex search
		ASSERT(strspn(ss, "0123456789abcdefABCDEF ?") == strlen(ss));
		NewHex(ss);
	}
}