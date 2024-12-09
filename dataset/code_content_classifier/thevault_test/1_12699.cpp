BOOL CFileEx::GetTimeLastModified( SYSTEMTIME& sys )
{
	BOOL bRet = FALSE;
	if( IsOpen() ) {
		bRet = CFileEx::GetTimeLastModified( m_lpFile, sys );
	}
	return bRet;
}