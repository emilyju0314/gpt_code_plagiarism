ULONGLONG CFileEx::Seek( LONGLONG lToMove, DWORD dwMoveFrom  )
{
	ULONGLONG		ulPos = 0;
	LARGE_INTEGER	lIn;
	LARGE_INTEGER	lOut;
	
	IsOpenThrows();

	if( ( lToMove <= ( LONGLONG )GetFileSize() ) ) {
		if( ( dwMoveFrom == FILE_BEGIN ) ||
			( dwMoveFrom == FILE_END ) ||
			( dwMoveFrom == FILE_CURRENT ) )
		{
			lIn.QuadPart = lToMove;

			if( ::SetFilePointerEx( m_hFile, lIn, &lOut, dwMoveFrom ) ) {
				ulPos = lOut.QuadPart;
			}else{
				ThrowErr( ::GetLastError(), FALSE );
			}
			
		}else{
			ThrowErr( FILEEX_ERR_PARAM_OUTOFRANGE, TRUE );
		}
	}	

	return ulPos;
}