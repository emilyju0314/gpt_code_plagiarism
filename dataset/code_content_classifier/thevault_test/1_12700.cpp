BOOL CFileEx::GetTimeCreated( SYSTEMTIME& sys )
{
	BOOL bRet = FALSE;
	if( IsOpen() ) {
		bRet = CFileEx::GetTimeCreated( m_lpFile, sys );
	}
	return bRet;
}