BOOL CFileEx::GetTimeLastAccessed( SYSTEMTIME& sys )
{
	BOOL bRet = FALSE;
	if( IsOpen() ) {
		bRet = CFileEx::GetTimeLastAccessed( m_lpFile, sys );
	}
	return bRet;
}