BOOL CFileEx::SetOvSegReadWriteSize( DWORD dwSegmentSize  )
{
	BOOL bSet = FALSE;
	if( dwSegmentSize <= 0 ) {
		ThrowErr( FILEEX_ERR_PARAM_OUTOFRANGE, 0 );
	}
	
	if( ! m_bActiveOvIO ) {
		bSet		= TRUE;
		m_dwSegSize = dwSegmentSize;
	}else{
		ThrowErr( FILEEX_ERR_OTHERIO_CURRENTLY_RUNNG, 0 );
	}

	return bSet;
}