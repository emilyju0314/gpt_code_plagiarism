DWORD CFileEx::Write( BYTE* pBuffer, DWORD dwSize )
{
	DWORD		dwWrote	= 0;
	BOOL		bRet	= FALSE;
	DWORD		dwErr	= 0;
	OVERLAPPED	ov;
	
	ZeroMemory( &ov, sizeof( OVERLAPPED ) );
	
	IsOpenThrows();

	if( pBuffer ) {
		//bRet	= ::WriteFile( m_hFile, pBuffer, dwSize, &dwWrote, &ov );
		bRet	= ::WriteFile( m_hFile, pBuffer, dwSize, &dwWrote, NULL );
		dwErr	= ::GetLastError();
		if( ! bRet && ( dwErr == ERROR_IO_PENDING ) ) {
			::GetOverlappedResult( m_hFile, &ov, &dwWrote, TRUE );
		}else{
				// some API call failed. To Determine reason throw error
				// back to user with the API call's error from GetLastError
			if( ! bRet ) {
				dwWrote = 0;
				ThrowErr( ::GetLastError(), FALSE );
			}
		}
	}else{
		ThrowErr( FILEEX_ERR_INVALIDPARAM, TRUE );
	}

	return dwWrote;
}