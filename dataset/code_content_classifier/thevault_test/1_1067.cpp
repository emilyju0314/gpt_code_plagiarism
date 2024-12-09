void FX_FireBullets( 
	int	iPlayerIndex,
	const Vector &vOrigin,
	const QAngle &vAngles,
	int	iWeaponID,
	int	iMode,
	int iSeed,
	float flSpread,
	bool bShouldPlaySound
	)
{
	Assert(vOrigin.IsValid());

	bool bDoEffects = true;

#ifdef CLIENT_DLL
	C_SDKPlayer *pPlayer = ToSDKPlayer( ClientEntityList().GetBaseEntity( iPlayerIndex ) );
#else
	CSDKPlayer *pPlayer = ToSDKPlayer( UTIL_PlayerByIndex( iPlayerIndex) );
#endif

	CSDKWeaponInfo *pWeaponInfo = CSDKWeaponInfo::GetWeaponInfo((SDKWeaponID)iWeaponID);
	if ( !pWeaponInfo )
	{
		DevMsg("FX_FireBullets: weapon alias for ID %i not found\n", iWeaponID );
		Assert(pWeaponInfo);
		return;
	}

#ifdef CLIENT_DLL
	bDoEffects = prediction->IsFirstTimePredicted();

	// Do the firing animation event.
	if ( pPlayer && !pPlayer->IsDormant() && bDoEffects )
	{
		pPlayer->m_PlayerAnimState->DoAnimationEvent( PLAYERANIMEVENT_ATTACK_PRIMARY );
	}
#else
	// if this is server code, send the effect over to client as temp entity
	// Dispatch one message for all the bullet impacts and sounds.
	TE_FireBullets( 
		iPlayerIndex,
		vOrigin, 
		vAngles, 
		iWeaponID,
		iMode,
		iSeed,
		flSpread
		);
#endif

	iSeed++;

	int		iDamage = pWeaponInfo->m_iDamage;
	int		iAmmoType = pWeaponInfo->iAmmoType;

	WeaponSound_t sound_type = SINGLE;

	if ( bDoEffects)
	{
#ifdef CLIENT_DLL
		if (pPlayer)
			pPlayer->m_flMuzzleFlashYaw = random->RandomFloat(0, 360);
		//ProjectedLightEffectManager( iPlayerIndex ).TriggerMuzzleFlash();
#endif

		if (bShouldPlaySound)
			FX_WeaponSound(iPlayerIndex, sound_type, vOrigin, pWeaponInfo);
	}


	// Fire bullets, calculate impacts & effects

	if ( !pPlayer )
		return;

	if (*pWeaponInfo->m_szSingle)
	{
		CWeaponSDKBase* pWeapon = pPlayer->GetActiveSDKWeapon();
		if (pWeapon)
		{
			Assert(pWeapon->IsAkimbo());
			CAkimboBase* pAkimbo = dynamic_cast<CAkimboBase*>(pWeapon);
			Assert(pAkimbo);
			if (pAkimbo)
				pPlayer->DoMuzzleFlash(pAkimbo->m_bShootRight?2:1);
		}
	}
	else
		pPlayer->DoMuzzleFlash();

	pPlayer->ReadyWeapon();

	StartGroupingSounds();

#if !defined (CLIENT_DLL)
	// Move other players back to history positions based on local player's lag
	lagcompensation->StartLagCompensation( pPlayer, pPlayer->GetCurrentCommand() );

	const int iMaxPlayers = 64;
	Vector avecMins[iMaxPlayers];
	Vector avecMaxs[iMaxPlayers];

	for (int i = 1; i <= min(iMaxPlayers, gpGlobals->maxClients); i++)
	{
		CSDKPlayer* pPlayer = ToSDKPlayer(UTIL_PlayerByIndex(i));
		if (!pPlayer)
			continue;

		avecMins[i] = pPlayer->CollisionProp()->OBBMins();
		avecMaxs[i] = pPlayer->CollisionProp()->OBBMaxs();

		pPlayer->SetSize(avecMins[i]*3, avecMaxs[i]*3);
	}
#endif

	for ( int iBullet=0; iBullet < pWeaponInfo->m_iBullets; iBullet++ )
	{
		RandomSeed( iSeed );	// init random system with this seed

		// Get circular gaussian spread.
		float x, y;
		x = RandomFloat( -0.5, 0.5 ) + RandomFloat( -0.5, 0.5 );
		y = RandomFloat( -0.5, 0.5 ) + RandomFloat( -0.5, 0.5 );
	
		iSeed++; // use new seed for next bullet

		pPlayer->FireBullet(
			vOrigin,
			vAngles,
			flSpread,
			(SDKWeaponID)iWeaponID,
			iDamage,
			iAmmoType,
			pPlayer,
			bDoEffects,
			x,y );
	}

	// Adjust the style charge spend for the fire rate of the weapon so that weapons with a high ROF don't suck it up.
	pPlayer->UseStyleCharge(SKILL_MARKSMAN, pWeaponInfo->m_flCycleTime * 10);

#if !defined (CLIENT_DLL)
	for (int i = 1; i <= min(iMaxPlayers, gpGlobals->maxClients); i++)
	{
		CSDKPlayer* pPlayer = ToSDKPlayer(UTIL_PlayerByIndex(i));
		if (!pPlayer)
			continue;

		pPlayer->SetSize(avecMins[i], avecMaxs[i]);
	}

	lagcompensation->FinishLagCompensation( pPlayer );
#endif

	EndGroupingSounds();
}