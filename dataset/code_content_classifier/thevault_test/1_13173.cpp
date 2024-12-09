int countTabs(string s)
{
	const char tab = '\t';
	const char* tabSpaces = "    ";
	int num = 0;
	while (s[0] == tab || s.substr(0, 4) == tabSpaces)
	{
		if (s[0] == tab)
		{
			s = s.substr(1);
			num++;
		}
		else
		{
			s = s.substr(4);
			num += 4;
		}
	}
	return num;
}