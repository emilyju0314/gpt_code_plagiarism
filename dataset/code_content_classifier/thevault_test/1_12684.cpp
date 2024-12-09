void CFileEx::ThrowErr( DWORD dwCode, BOOL bIsCust )
{
	if( m_bThrowErrs ) {
		if( bIsCust ) {
			throw CFileExException( 0, dwCode );
		}else{
			throw CFileExException( dwCode, 0 );
		}
	}

	return;
}