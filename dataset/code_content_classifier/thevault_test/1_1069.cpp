void CSDKTeamMenu::OnCommand( const char *command )
{
	if ( Q_strncmp( command, "jointeam ", 9 ) == 0 )
	{
		gViewPortInterface->ShowBackGround( false );

		BaseClass::OnCommand( command );

		engine->ServerCmd( command );

		// Until the message goes to the server and comes back we stuff teamnum
		// so that it has the proper value and we don't get circular menus.
		// A hack, but I want to ship.
		if (C_SDKPlayer::GetLocalSDKPlayer())
			C_SDKPlayer::GetLocalSDKPlayer()->m_iTeamNum = atoi(command+9);

		GetFolderMenu()->ShowPage( PANEL_CLASS );
	}
	else
		BaseClass::OnCommand(command);
}