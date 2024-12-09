void CHudWeaponSelection::CycleToNextWeapon( void )
{
	// Get the local player.
	C_SDKPlayer *pPlayer = C_SDKPlayer::GetLocalSDKPlayer();
	if ( !pPlayer )
		return;

	C_WeaponSDKBase* pActiveWeapon = pPlayer->GetActiveSDKWeapon();
	if (!pActiveWeapon)
	{
		for (int i = 0; i < DA_MAX_WEAPON_SLOTS; i++)
			m_aflSelectedGoal[i] = 0;

		m_aflSelectedGoal[0] = 1;

		SetSelectedWeapon( m_ahWeaponSlots[0] );
		return;
	}

	if ( !IsInSelectionMode() )
		OpenSelection();

	int iSlot = -1;
	C_BaseCombatWeapon* pSelectedWeapon = GetSelectedWeapon();

	if (hud_fastswitch.GetBool())
		pSelectedWeapon = pPlayer->GetActiveSDKWeapon();

	for (int i = 0; i < DA_MAX_WEAPON_SLOTS; i++)
	{
		if (m_ahWeaponSlots[i] == pSelectedWeapon)
		{
			iSlot = i;
			break;
		}
	}

	if (iSlot < 0)
		return;

	while (!m_ahWeaponSlots[(++iSlot) % DA_MAX_WEAPON_SLOTS]);

	iSlot %= DA_MAX_WEAPON_SLOTS;

	SetSelectedWeapon( m_ahWeaponSlots[iSlot] );

	for (int i = 0; i < DA_MAX_WEAPON_SLOTS; i++)
		m_aflSelectedGoal[i] = 0;

	m_aflSelectedGoal[iSlot] = 1;

	m_flDeployGoal = 1;

	// Play the "cycle to next weapon" sound
	pPlayer->EmitSound( "Player.WeaponSelectionMoveSlot" );
}