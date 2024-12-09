void CHudWeaponSelection::FastWeaponSwitch( int iWeaponSlot )
{
	// get the slot the player's weapon is in
	C_SDKPlayer *pPlayer = C_SDKPlayer::GetLocalSDKPlayer();
	if ( !pPlayer )
		return;

	if (iWeaponSlot < 0 || iWeaponSlot >= DA_MAX_WEAPON_SLOTS)
		return;

	if (!m_ahWeaponSlots[iWeaponSlot])
	{
		pPlayer->EmitSound( "Player.DenyWeaponSelection" );
		return;
	}

	if (pPlayer->GetActiveSDKWeapon() == GetSelectedWeapon())
		return;

	m_flDeployGoal = 1;

	// select the new weapon
	::input->MakeWeaponSelection( m_ahWeaponSlots[iWeaponSlot] );
}