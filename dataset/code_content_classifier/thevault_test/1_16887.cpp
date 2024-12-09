char *ModuleName(char *pSourceFileName)
{
	int x = (int)MFString_Length(pSourceFileName)-1;

	while(x >= 0 && pSourceFileName[x] != '/' && pSourceFileName[x] != '\\')
	{
		--x;
	}

	return x == -1 ? pSourceFileName : &pSourceFileName[x+1];
}