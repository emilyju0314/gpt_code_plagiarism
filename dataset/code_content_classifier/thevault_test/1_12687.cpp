void CFileEx::Close()
{
	if( m_bActiveOvIO ) {
			// just set the stop event.  The IO routine will recall this function
			// on its way out to do the proper close.
		::SetEvent( m_hStop );
		m_bShouldClose = TRUE;
	}else{
		::CloseHandle( m_hFile );
		m_hFile			= NULL;
		m_bOpen			= FALSE;
		m_bShouldClose	= FALSE;
	}

	return;
}