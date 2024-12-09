void CHudWeaponSelection::SelectWeaponSlot( int iSlot )
{
	// iSlot is one higher than it should be, since it's the number key, not the 0-based index into the weapons
	--iSlot;

	// Get the local player.
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	if ( !pPlayer )
		return;

	// Don't try and read past our possible number of slots
	if ( iSlot > DA_MAX_WEAPON_SLOTS )
		return;

	// Make sure the player's allowed to switch weapons
	if ( pPlayer->IsAllowedToSwitchWeapons() == false )
		return;

	// do a fast switch if set
	if ( hud_fastswitch.GetBool() )
	{
		FastWeaponSwitch( iSlot );
		return;
	}

	if ( !IsInSelectionMode() )
		// open the weapon selection
		OpenSelection();

	C_BaseCombatWeapon *pActiveWeapon = m_ahWeaponSlots[iSlot];
	if (!pActiveWeapon)
		return;

	// Mark the change
	SetSelectedWeapon( pActiveWeapon );

	for (int i = 0; i < DA_MAX_WEAPON_SLOTS; i++)
		m_aflSelectedGoal[i] = 0;

	m_aflSelectedGoal[iSlot] = 1;

	m_flDeployGoal = 1;

	pPlayer->EmitSound( "Player.WeaponSelectionMoveSlot" );
}