bool ClientModeShared::ShouldDrawLocalPlayer( C_BasePlayer *pPlayer )
{
	if ( pPlayer->IsViewEntity() && !pPlayer->ShouldDrawLocalPlayer() )
		return false;

	return true;
}