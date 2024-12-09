static void UpdateAndDamageSAMIfFound(INT16 sSectorX, INT16 sSectorY, INT16 sSectorZ, INT16 sGridNo, void*, UINT8 ubDamage, BOOLEAN fIsDestroyed)
{
	// OK, First check if SAM exists, and if not, return
	if (!DoesSAMExistHere(sSectorX, sSectorY, sSectorZ, sGridNo))
	{
		return;
	}

	// Damage.....
	INT16 sSectorNo = CALCULATE_STRATEGIC_INDEX(sSectorX, sSectorY);
	STLOGD("SAM site at sector #{} is damaged by {} points", sSectorNo, ubDamage);
	if (StrategicMap[sSectorNo].bSAMCondition >= ubDamage)
	{
		StrategicMap[sSectorNo].bSAMCondition -= ubDamage;
	}
	else
	{
		StrategicMap[sSectorNo].bSAMCondition = 0;
	}

	// SAM site may have been put out of commission...
	UpdateAirspaceControl();

	// ATE: GRAPHICS UPDATE WILL GET DONE VIA NORMAL EXPLOSION CODE.....
}