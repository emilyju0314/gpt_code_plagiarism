BOOL CFileEx::GetTimeLastAccessed( LPCTSTR lpFile, SYSTEMTIME& sys )
{
	BOOL bRet = FALSE;
	WIN32_FILE_ATTRIBUTE_DATA fd;
	ZeroMemory( &fd, sizeof( WIN32_FILE_ATTRIBUTE_DATA ) );
	if( lpFile ) {
		if( ::GetFileAttributesEx( lpFile, GetFileExInfoStandard, ( void* ) &fd ) ) {
			::FileTimeToSystemTime( &fd.ftLastAccessTime, &sys );
			bRet = TRUE;
		}
	}

	return bRet;
}