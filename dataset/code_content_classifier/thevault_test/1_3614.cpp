int	ClientModeShared::KeyInput( int down, ButtonCode_t keynum, const char *pszCurrentBinding )
{
	if ( engine->Con_IsVisible() )
		return 1;

	// Should we start typing a message?
	if ( pszCurrentBinding &&
		( Q_strcmp( pszCurrentBinding, "messagemode" ) == 0 ||
		Q_strcmp( pszCurrentBinding, "say" ) == 0 ) )
	{
		if ( down )
		{
			StartMessageMode( MM_SAY );
		}
		return 0;
	}
	else if ( pszCurrentBinding &&
		( Q_strcmp( pszCurrentBinding, "messagemode2" ) == 0 ||
		Q_strcmp( pszCurrentBinding, "say_team" ) == 0 ) )
	{
		if ( down )
		{
			StartMessageMode( MM_SAY_TEAM );
		}
		return 0;
	}

	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();

	if ( IsJoystickCode( keynum ) )
	{
		keynum = GetBaseButtonCode( keynum );
	}

	// If SourceMod menu is open (they use CHudMenu), give it input priority.
	bool bIsHudMenuOpen = false;
	CHudMenu *pHudMenu = GET_HUDELEMENT( CHudMenu );
	bIsHudMenuOpen = ( pHudMenu && pHudMenu->IsMenuOpen() );
	if ( bIsHudMenuOpen && !HudElementKeyInput( down, keynum, pszCurrentBinding ) )
	{
		return 0;
	}

	// if ingame spectator mode, let spectator input intercept key event here
	if( pPlayer &&
		( pPlayer->GetObserverMode() > OBS_MODE_DEATHCAM ) &&
		!HandleSpectatorKeyInput( down, keynum, pszCurrentBinding ) )
	{
		return 0;
	}

	// Let game-specific hud elements get a crack at the key input
	if ( !HudElementKeyInput( down, keynum, pszCurrentBinding ) )
	{
		return 0;
	}

	C_BaseCombatWeapon *pWeapon = pPlayer ? pPlayer->GetActiveWeapon() : NULL;
	if ( pWeapon )
	{
		return pWeapon->KeyInput( down, keynum, pszCurrentBinding );
	}

	return 1;
}