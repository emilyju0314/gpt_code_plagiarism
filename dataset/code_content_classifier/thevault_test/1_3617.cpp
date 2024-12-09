int ClientModeShared::HudElementKeyInput( int down, ButtonCode_t keynum, const char *pszCurrentBinding )
{
	if ( GetFullscreenClientMode() && GetFullscreenClientMode() != this &&
		!GetFullscreenClientMode()->HudElementKeyInput( down, keynum, pszCurrentBinding ) )
		return 0;

	if ( CSGameRules() && CSGameRules()->IsEndMatchVotingForNextMap() )
	{
		// this looks messy, but essentially, if the convar is set to true, use the bindings, if not use the raw keys
		if ( down && (( spec_usenumberkeys_nobinds.GetBool() == false && pszCurrentBinding &&
			( ContainsBinding( pszCurrentBinding, "slot1" ) ||
			ContainsBinding( pszCurrentBinding, "slot2" ) ||
			ContainsBinding( pszCurrentBinding, "slot3" ) ||
			ContainsBinding( pszCurrentBinding, "slot4" ) ||
			ContainsBinding( pszCurrentBinding, "slot5" ) ||
			ContainsBinding( pszCurrentBinding, "slot6" ) ||
			ContainsBinding( pszCurrentBinding, "slot7" ) ||
			ContainsBinding( pszCurrentBinding, "slot8" ) ||
			ContainsBinding( pszCurrentBinding, "slot9" ) ||
			ContainsBinding( pszCurrentBinding, "slot10" ) ) )
			||
			( spec_usenumberkeys_nobinds.GetBool() == true &&
			( keynum == KEY_1 ||
			keynum == KEY_2 ||
			keynum == KEY_3 ||
			keynum == KEY_4 ||
			keynum == KEY_5 ||
			keynum == KEY_6 ||
			keynum == KEY_7 ||
			keynum == KEY_8 ||
			keynum == KEY_9 ||
			keynum == KEY_0 ) ) ) )
		{
			int slotnum = 0;
			if ( spec_usenumberkeys_nobinds.GetBool() )
			{
				slotnum = ( keynum - KEY_0 ) - 1;
			}
			else
			{
				char* slotnumberchar = ( char * )pszCurrentBinding + strlen( pszCurrentBinding ) - 1;
				slotnum = atoi( slotnumberchar ) - 1;
			}

			if ( slotnum < 0 )
				slotnum = 10 + slotnum;

			char commandBuffer[32];
			V_snprintf( commandBuffer, sizeof( commandBuffer ), "endmatch_votenextmap %d", slotnum );
			engine->ClientCmd( commandBuffer );

			return 0;
		}
	}

	if ( down && pszCurrentBinding && ContainsBinding( pszCurrentBinding, "radio1" ) )
	{
		/* Removed for partner depot */
		return 0;
	}

	if ( m_pWeaponSelection )
	{
		if ( !m_pWeaponSelection->KeyInput( down, keynum, pszCurrentBinding ) )
		{
			return 0;
		}
	}		

	return 1;
}