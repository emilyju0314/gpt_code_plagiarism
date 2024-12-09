CFileEx::~CFileEx()
{
	if( IsOpen() ) {
		Close();
	}

	::CloseHandle( m_hStop );
	m_hStop			= NULL;
	m_bActiveOvIO	= FALSE;

	return;
}