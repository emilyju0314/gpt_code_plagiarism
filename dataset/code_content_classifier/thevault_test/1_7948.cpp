int StoreUniverse(LPCTSTR lpszPathName, UNIVERSE *u, char *errbuf)
{
	const char *filename;

	filename = lpszPathName;
	return Universe_Write(u, filename, errbuf);
}