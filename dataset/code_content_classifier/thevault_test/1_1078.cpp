bool CSDKMapOverview::CanPlayerBeSeen( MapPlayer_t *player )
{
	C_BasePlayer *localPlayer = C_BasePlayer::GetLocalPlayer();

	if (!localPlayer || !player )
		return false;

	//Tony; if local player is spectating, just check base.
	if (localPlayer->GetTeamNumber() == TEAM_SPECTATOR )
		return BaseClass::CanPlayerBeSeen(player);

	SDKMapPlayer_t *SDKPlayer = GetSDKInfoForPlayer(player);
		
	if ( !SDKPlayer )
		return false;

	if( player->health <= 0 )
	{
		// Have to be under the overriden icon time to draw when dead.
		if ( SDKPlayer->overrideExpirationTime == -1  ||  SDKPlayer->overrideExpirationTime <= gpGlobals->curtime )
			return false;
	}
	
	return BaseClass::CanPlayerBeSeen(player);
}