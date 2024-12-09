float RangedManager::getThreatRange(const sc2::Unit * rangedUnit, const sc2::Unit * threat)
{
	sc2::GameInfo gameInfo = m_bot.Observation()->GetGameInfo();
	float heightBonus = Util::TerainHeight(gameInfo, threat->pos) > Util::TerainHeight(gameInfo, rangedUnit->pos) + HARASS_THREAT_MIN_HEIGHT_DIFF ? HARASS_THREAT_RANGE_HEIGHT_BONUS : 0.f;
	float threatRange = Util::GetAttackRangeForTarget(threat, rangedUnit, m_bot) + Util::getSpeedOfUnit(threat, m_bot) + heightBonus + HARASS_THREAT_RANGE_BUFFER;
	return threatRange;
}