DWORD CFileEx::ReadOv( BYTE* pBuffer, DWORD dwSize, LPFN_LRGFILEOP_PROGCALLBACK lpCallback, LPVOID pParam, BOOL bUseMsgPump )
{
	DWORD dwRead = 0;
	
	IsOpenThrows();

	if( pBuffer ) {
		m_bActiveOvIO = TRUE;
		if( bUseMsgPump ) {
			dwRead = DoFileOperationWithMsgPump( FALSE, pBuffer, dwSize, lpCallback, pParam );
		}else{
			dwRead = DoFileOperation( FALSE, pBuffer, dwSize, lpCallback, pParam );
		}
		m_bActiveOvIO = FALSE;

		if( m_bShouldClose ) {
				// this close rountine will now actually shut the file because 
				// the m_bActiveOvIo flag is false.
			Close();
		}

	}else{
		ThrowErr( FILEEX_ERR_INVALIDPARAM, TRUE );
	}

	return dwRead;
}