void CFileEx::Flush()
{
	IsOpenThrows();
    if( ! ::FlushFileBuffers( m_hFile ) ) {
		ThrowErr( ::GetLastError(), FALSE );
	}
	
	return;
}