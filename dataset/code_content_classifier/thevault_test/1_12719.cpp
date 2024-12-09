void DisplayErrorMessage( HRESULT hr )
{
	char strMsg[512];

	GetErrorMessage( hr, strMsg );

	MessageBox( NULL, strMsg, WINDOWNAME, MB_ICONERROR|MB_OK );
}