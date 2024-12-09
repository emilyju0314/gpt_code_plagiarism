BOOL CFileEx::AbortOverlappedOperation()
{
	BOOL bRet = FALSE;
	if( m_bActiveOvIO ) {
		::SetEvent( m_hStop );
		bRet = TRUE;
	}
	return bRet;
}