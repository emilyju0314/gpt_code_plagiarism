void ClientModeShared::OverrideMouseInput( float *x, float *y )
{
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	C_BaseCombatWeapon *pWeapon = pPlayer ? pPlayer->GetActiveWeapon() : NULL;;
	if ( pWeapon )
	{
		pWeapon->OverrideMouseInput( x, y );
	}
}