bool CheckVarRange_Generic( ConVar *pVar, int minVal, int maxVal )
{
	// Don't reenter (resetting the variable when we're checking the range might cause us to reenter here).
	static bool bInFunction = false;
	if ( bInFunction )	
		return true;
	bInFunction = true;

	if ( !CanCheat() && !Host_IsSinglePlayerGame() )
	{
		int clampedValue = clamp( pVar->GetInt(), minVal, maxVal );
		if ( clampedValue != pVar->GetInt() )
		{
			Warning( "sv_cheats=0 prevented changing %s outside of the range [0,2] (was %d).\n", pVar->GetName(), pVar->GetInt() );
			pVar->SetValue( clampedValue );
		}
	}

	bInFunction = false;
	return false;
}