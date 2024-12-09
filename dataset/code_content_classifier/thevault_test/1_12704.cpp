BOOL CFileEx::NextIoSegment( BOOL bWrite, RDWROVERLAPPEDPLUS& ovp, BYTE* pBuffer, DWORD dwTtlSegs, DWORD dwCurSeg )
{
	BOOL	bSuccess	= FALSE;
	BYTE*	pOffBuf		= NULL;
	DWORD	dwTransfer	= 0;


	pOffBuf			= ( BYTE* ) POINTEROFFSET( pBuffer, ovp.dwTotalSoFar );
	dwTransfer		= ( dwCurSeg == dwTtlSegs ) ? ( ovp.dwTotalSizeToTransfer % m_dwSegSize ) : m_dwSegSize;
	ovp.ov.Offset	= ovp.dwTotalSoFar;

	if( bWrite ) {
		bSuccess = ::WriteFileEx(	m_hFile, pOffBuf, dwTransfer, &ovp.ov, 
									CFileEx::FileIoCompletionRoutine );
	}else{
		bSuccess = ::ReadFileEx(	m_hFile, pOffBuf, dwTransfer, &ovp.ov, 
									CFileEx::FileIoCompletionRoutine );
	}		

	return bSuccess;
}