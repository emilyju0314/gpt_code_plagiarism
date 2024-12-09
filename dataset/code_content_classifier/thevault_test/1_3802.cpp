const char * GetExecutableFilename()
{
#ifdef _PS3
	return "csgo";
#else // !_PS3
	char exepath[MAX_PATH];
	static char filename[MAX_PATH];

#ifdef WIN32
	filename[0] = 0;
	if ( GetExecutableName( exepath, sizeof( exepath ) ) )
	{
		_splitpath
		( 
			exepath, // Input
			NULL,  // drive
			NULL,  // dir
			filename, // filename
			NULL // extension
		);
	}

	Q_strlower( filename );
#else
	filename[0] = 0;
#endif
	return filename;
#endif // _PS3
}