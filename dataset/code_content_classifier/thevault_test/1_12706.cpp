DWORD CFileEx::DoFileOperationWithMsgPump( BOOL bWrite, BYTE* pBuffer, DWORD dwSize, LPFN_LRGFILEOP_PROGCALLBACK lpCallback, LPVOID pParam )
{
	RDWROVERLAPPEDPLUS	ovp;
	DWORD				dwNumSegs	= 0,						
						dwCurSeg	= 1;
	BOOL				bDone		= FALSE,
						bQuit		= 0;
	int					nRet		= 0;
	
	ZeroMemory( &ovp.ov, sizeof( OVERLAPPED ) );
	ovp.lpCallback				= lpCallback;
	ovp.pParam					= pParam;
	ovp.dwTotalSizeToTransfer	= dwSize;
	ovp.dwTotalSoFar			= 0;
	ovp.dwError					= 0;
	ovp.bContinue				= TRUE;

	dwNumSegs = ( dwSize + m_dwSegSize - 1 ) / m_dwSegSize;	// <-- eliviates need for floating point lib calc.	
	
	if( ! NextIoSegment( bWrite, ovp, pBuffer, dwNumSegs, dwCurSeg ) ) {
			// something fouled up in our NextIoSegment routine ( ReadFileEx or WriteFilEx failed )
			// so we set the error in the ovp structure and set quit and fake the nRet code.  By 
			// doing this an exception will be thrown on the way out of this function. setting bDone
			// to TRUE makes sure the loop never runs.
		ovp.dwError = ::GetLastError();
		bQuit		= TRUE;
		nRet		= WAIT_IO_COMPLETION;
		bDone		= TRUE;
	}

	while( ! bDone ) {
		nRet = ::MsgWaitForMultipleObjectsEx( 1, &m_hStop, INFINITE, QS_ALLEVENTS, MWMO_ALERTABLE );
		switch( nRet ) 
		{
			case WAIT_OBJECT_0:			bQuit = TRUE;	::ResetEvent( m_hStop );	break;
			case WAIT_OBJECT_0 + 1:		PumpMsgs();									break;
			case WAIT_IO_COMPLETION:
				{
					bDone = ( ovp.dwTotalSoFar == ovp.dwTotalSizeToTransfer );
	
					if( bDone || bQuit) {
						break;
					}
							// this signals either an error happened on the last I/O
							// compeletion rountine or the user returned FALSE from their
							// callback signaling to stop the IO process.
					if( ! ovp.bContinue ) {							
						bQuit = TRUE;
					}else{
						dwCurSeg++;
						if( ! NextIoSegment( bWrite, ovp, pBuffer, dwNumSegs, dwCurSeg ) ) {
							// something failed with our read/write call. This is an API error
							// so we need to handle it accordingly. Setting the ovp.dwError 
							// and setting Quit to TRUE will force an exception to be thrown
							// back to the user notifying them of the failure.
							ovp.dwError = ::GetLastError();
							bQuit		= TRUE;
						}
					}
				}
				break;
		};	

			// For Some reason we are now dropping out of this loop. This is mostly
			// likely a kill event that got signaled but we need to check for an
			// actual API error just in case.
		if( ( nRet == WAIT_IO_COMPLETION ) && bQuit ) {
			if( ovp.dwError != 0 ) {
				ThrowErr( ovp.dwError, FALSE );
			}
			break;
		}
	}

	return ovp.dwTotalSoFar;
}