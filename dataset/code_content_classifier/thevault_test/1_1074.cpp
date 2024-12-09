void CSDKSpectatorGUI::UpdateTimer()
{
	wchar_t szText[ 63 ];

	
	m_nLastTime = (int)( SDKGameRules()->GetMapRemainingTime() );

	if ( m_nLastTime < 0 )
		 m_nLastTime  = 0;

	_snwprintf ( szText, sizeof( szText ) / sizeof( wchar_t ), L"%d:%02d", (m_nLastTime / 60), (m_nLastTime % 60) );
	szText[62] = 0;

	SetLabelText("timerlabel", szText );
}