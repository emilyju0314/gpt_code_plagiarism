void CSDKTeamMenu::Update( void )
{
	BaseClass::Update();

	// The character was changed. Reload control settings so that animation is updated.
	LoadControlSettings( "Resource/UI/TeamMenu.res" );

	C_SDKPlayer *pPlayer = C_SDKPlayer::GetLocalSDKPlayer();
	
	if ( !pPlayer )
		return;

	Label *pStatusLabel = dynamic_cast<Label *>(FindChildByName("blueteaminfo"));
	C_Team *team = GetGlobalTeam(SDK_TEAM_BLUE);
	if (pStatusLabel && team)
	{
		wchar_t szFmt[128]=L"";
		const wchar_t *pchFmt = g_pVGuiLocalize->Find( "#DA_TeamMenu_Info" );
		if ( pchFmt && pchFmt[0] )
		{
			wchar_t szText[512]=L"";
			wchar_t szNumPlayersOnTeam[ 10 ];
			
			Q_wcsncpy( szFmt, pchFmt, sizeof( szFmt ) );
			_snwprintf( szNumPlayersOnTeam, ARRAYSIZE(szNumPlayersOnTeam) - 1, L"%d",  team->Get_Number_Players() );
			g_pVGuiLocalize->ConstructString( szText, sizeof( szText ), szFmt, 1, szNumPlayersOnTeam );

			pStatusLabel->SetText(szText);
		}
	}

	pStatusLabel = dynamic_cast<Label *>(FindChildByName("redteaminfo"));
	team = GetGlobalTeam(SDK_TEAM_RED);
	if (pStatusLabel && team)
	{
		wchar_t szFmt[128]=L"";
		const wchar_t *pchFmt = g_pVGuiLocalize->Find( "#DA_TeamMenu_Info" );
		if ( pchFmt && pchFmt[0] )
		{
			wchar_t szText[512]=L"";
			wchar_t szNumPlayersOnTeam[ 10 ];
			
			Q_wcsncpy( szFmt, pchFmt, sizeof( szFmt ) );
			_snwprintf( szNumPlayersOnTeam, ARRAYSIZE(szNumPlayersOnTeam) - 1, L"%d",  team->Get_Number_Players() );
			g_pVGuiLocalize->ConstructString( szText, sizeof( szText ), szFmt, 1, szNumPlayersOnTeam );

			pStatusLabel->SetText(szText);
		}
	}

	UpdateCharacter(m_pCharacterImageRed);
	UpdateCharacter(m_pCharacterImageBlue);
}