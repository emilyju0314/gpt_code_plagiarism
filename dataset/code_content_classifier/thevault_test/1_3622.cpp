bool XBX_SetProfileDefaultSettings( int iController )
{
	// These defined values can't play nicely with the PC, so we need to ignore them for that build target
#ifdef _GAMECONSOLE
	UserProfileData upd = {0};
	if ( IPlayerLocal *pPlayerLocal = g_pMatchFramework->GetMatchSystem()->GetPlayerManager()->GetLocalPlayer( iController ) )
	{
		upd = pPlayerLocal->GetPlayerProfileData();
	}

	//
	// Skill
	//

	int nSkillSetting = upd.difficulty;
	int nResultSkill = 2;
#ifdef _X360
	switch( nSkillSetting )
	{
	case XPROFILE_GAMER_DIFFICULTY_HARD:
		nResultSkill = 3;
		break;
	
	case XPROFILE_GAMER_DIFFICULTY_EASY:
	default:
		nResultSkill = 1;
		break;
	}
#endif

	// If the mod has no difficulty setting, only easy is allowed
	KeyValues *modinfo = new KeyValues("ModInfo");
	if ( modinfo->LoadFromFile( g_pFileSystem, "gameinfo.txt" ) )
	{
		if ( stricmp(modinfo->GetString("nodifficulty", "0"), "1") == 0 )
			nResultSkill = 1;
	}
	modinfo->deleteThis();

	char szScratch[MAX_PATH];
	Q_snprintf( szScratch, sizeof(szScratch), "skill %d", nResultSkill );
	Cbuf_AddText( Cbuf_GetCurrentPlayer(), szScratch );

	// 
	// Movement control
	//

	int nMovementControl = !!upd.action_movementcontrol;

	Q_snprintf( szScratch, sizeof(szScratch), "joy_movement_stick %d", nMovementControl );
	Cbuf_AddText( Cbuf_GetCurrentPlayer(), szScratch );

	Cbuf_AddText( Cbuf_GetCurrentPlayer(), "joyadvancedupdate" );

	// 
	// Y-Inversion
	//

	int nYinvert = !!upd.yaxis;
	
	Q_snprintf( szScratch, sizeof(szScratch), "joy_inverty %d", nYinvert );
	Cbuf_AddText( Cbuf_GetCurrentPlayer(), szScratch );
	
	//
	// Vibration control
	//

	int nVibration = !!upd.vibration;

	Q_snprintf( szScratch, sizeof(szScratch), "cl_rumblescale %d", nVibration );
	Cbuf_AddText( Cbuf_GetCurrentPlayer(), szScratch );

	// Execute all commands we've queued up
	Cbuf_Execute();
#endif // _GAMECONSOLE

	return true;
}