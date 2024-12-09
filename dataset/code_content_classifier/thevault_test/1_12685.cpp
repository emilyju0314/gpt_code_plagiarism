void CFileEx::IsOpenThrows()
{
	if( ! IsOpen() ) {
		ThrowErr( FILEEX_ERR_INVALID_OPCLOSEDFILE, TRUE );
	}
}