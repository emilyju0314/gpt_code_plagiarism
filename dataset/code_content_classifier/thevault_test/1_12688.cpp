DWORD CFileEx::Read( BYTE* pBuffer, DWORD dwSize )
{
	DWORD		dwRead	= 0;
	BOOL		bRet	= FALSE;
	OVERLAPPED	ov;

	ZeroMemory( &ov, sizeof( OVERLAPPED ) );
	IsOpenThrows();
	
	if( pBuffer ) {
		//bRet = ::ReadFile( m_hFile, pBuffer, dwSize, &dwRead, &ov );
		bRet = ::ReadFile( m_hFile, pBuffer, dwSize, &dwRead, 0);
		if( ! bRet && ::GetLastError() == ERROR_IO_PENDING ) {
			::GetOverlappedResult( m_hFile, &ov, &dwRead, TRUE );
		}else{
				// some API call failed. To Determine reason throw error
				// back to user with the API call's error from GetLastError
			if( ! bRet ) {
				dwRead = 0;
				ThrowErr( ::GetLastError(), FALSE );
			}
		}
	}else{
		ThrowErr( FILEEX_ERR_INVALIDPARAM, TRUE );
	}

	return dwRead;
}