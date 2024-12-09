BOOL CFileEx::Open( LPCTSTR lpFile, DWORD dwCreateDisp, DWORD dwAccess, DWORD dwShare, LPSECURITY_ATTRIBUTES lpSec )
{
	if( IsOpen() ) {
		Close();
	}

	if( ( lpFile == NULL ) || ( lstrlen( lpFile ) > _MAX_PATH ) ) {
		return FALSE;
	}

//	m_hFile = ::CreateFile( lpFile, dwAccess, dwShare, lpSec, dwCreateDisp, FILE_FLAG_OVERLAPPED, NULL );
	m_hFile = ::CreateFile(lpFile, dwAccess, dwShare, lpSec, dwCreateDisp, 0, NULL );
			
	if( m_hFile == INVALID_HANDLE_VALUE ) {
			// file open failed.  Throw error back to the user with the
			// windows error code.
		ThrowErr( ::GetLastError(), FALSE );
		m_hFile = NULL;		
	}else{
		::_tcscpy( m_lpFile, lpFile );
		m_bOpen = TRUE;
	}

	return m_bOpen;
}