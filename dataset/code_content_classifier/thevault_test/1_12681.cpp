CFileEx::CFileEx()
{
	m_hFile			= NULL;
	m_bOpen			= FALSE;
	m_hStop			= ::CreateEvent( NULL, TRUE, FALSE, NULL );
	m_dwSegSize		= OVLFILE_DEFAULT_SEGSIZE;
	m_bActiveOvIO	= FALSE;
	m_bThrowErrs	= TRUE;
	m_bShouldClose	= FALSE;

	ZeroMemory( m_lpFile, sizeof( TCHAR ) * _MAX_PATH );

	return;
}