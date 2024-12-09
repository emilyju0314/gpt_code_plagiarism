void CNPC_ShadowWalker::FoundEnemySound(void)
{
	if (gpGlobals->curtime > m_flNextFoundEnemySoundTime)
	{
		m_flNextFoundEnemySoundTime = gpGlobals->curtime + random->RandomFloat(MIN_TIME_NEXT_FOUNDENEMY_SOUND, MAX_TIME_NEXT_FOUNDENEMY_SOUND);
		PlaySound(m_iszFoundEnemySound, true);
	}
}