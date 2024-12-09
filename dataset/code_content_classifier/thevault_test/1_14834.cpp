static void HandleCriticalHitForVehicleInLocation(const UINT8 ubID, const INT16 sDmg, const INT16 sGridNo, SOLDIERTYPE* const att)
{
	// check state the armor was s'posed to be in vs. the current state..the difference / orig state is % chance
	// that a critical hit will occur
	BOOLEAN	fMadeCorpse = FALSE;

	VEHICLETYPE& v  = pVehicleList[ubID];
	SOLDIERTYPE& vs = GetSoldierStructureForVehicle(v);

	if (sDmg > vs.bLife)
	{
		vs.bLife = 0;
	}
	else
	{
		// Decrease Health
		vs.bLife -= sDmg;
	}

	if (vs.bLife < OKLIFE) vs.bLife = 0;

	//Show damage
	vs.sDamage += sDmg;

	if (vs.bInSector && vs.bVisible != -1)
	{
		// If we are already dead, don't show damage!
		if ( sDmg != 0 )
		{
			// Display damage

			// Set Damage display counter
			vs.fDisplayDamage = TRUE;
			vs.bDisplayDamageCount = 0;

			vs.sDamageX = vs.sBoundingBoxOffsetX;
			vs.sDamageY = vs.sBoundingBoxOffsetY;
		}
	}

	if (vs.bLife == 0 && !v.fDestroyed)
	{
		v.fDestroyed = TRUE;

		// Explode vehicle...
		IgniteExplosion(att, 0, sGridNo, GREAT_BIG_EXPLOSION, 0);

		CheckForAndHandleSoldierDeath(&vs, &fMadeCorpse);

		KillAllInVehicle(v);
	}
}