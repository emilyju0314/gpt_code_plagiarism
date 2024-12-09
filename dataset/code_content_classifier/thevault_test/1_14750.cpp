static void SetOffBoobyTrapInMapScreen(SOLDIERTYPE* pSoldier, OBJECTTYPE* pObject)
{
	UINT8 ubPtsDmg = 0;

	// check if trapped item is an explosive, if so then up the amount of dmg
	if( ( pObject -> usItem == TNT )|| (  pObject -> usItem == RDX ) )
	{
		// for explosive
		ubPtsDmg = 0;
	}
	else
	{
		// normal mini grenade dmg
		ubPtsDmg = 0;
	}

	// injure the inventory character
	SoldierTakeDamage(pSoldier, ubPtsDmg, ubPtsDmg, TAKE_DAMAGE_EXPLOSION, NULL);

	// play the sound
	PlayJA2Sample(EXPLOSION_1, BTNVOLUME, 1, MIDDLEPAN);
}