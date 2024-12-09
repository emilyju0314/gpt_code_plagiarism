void
CChangeSetBuilder::outputString (const char *inStr, bool isCommand)
{
	THROW_IF (inStr == NULL, XBadParameter);
	
	if (! isCommand)
	{
		THROW_IF (fputs ("> ", mOutFile) == EOF, XCantWrite);
	}

	THROW_IF (fputs (inStr, mOutFile) == EOF, XCantWrite);
	THROW_IF (fputc ('\n', mOutFile) == EOF, XCantWrite);
}