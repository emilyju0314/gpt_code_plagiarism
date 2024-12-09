static UINT32 PercentEnemiesKilled()
{
	Assert(gTacticalStatus.Team[ ENEMY_TEAM ].bMenInSector >= 0);
	UINT32 totalEnemies = static_cast<UINT32>(gTacticalStatus.Team[ ENEMY_TEAM ].bMenInSector) + gTacticalStatus.ubArmyGuysKilled;
	if (totalEnemies == 0)
	{
		SLOGW("PercentEnemiesKilled was expecting the army in the current sector");
		return 0;
	}
	return 100 * static_cast<UINT32>(gTacticalStatus.ubArmyGuysKilled) / totalEnemies;
}