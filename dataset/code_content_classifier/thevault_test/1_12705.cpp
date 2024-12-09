void CFileEx::PumpMsgs()
{
	MSG	msg;
	while( ::PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) ) {
		::GetMessage( &msg, NULL, 0, 0 );
		::TranslateMessage( &msg );
		::DispatchMessage( &msg );
	}

	return;
}