const std::vector<const sc2::Unit *> RangedManager::getThreats(const sc2::Unit * rangedUnit, const std::vector<const sc2::Unit *> & targets)
{
	BOT_ASSERT(rangedUnit, "null ranged unit in getThreats");

	std::vector<const sc2::Unit *> threats;

	// for each possible threat
	for (auto targetUnit : targets)
	{
		BOT_ASSERT(targetUnit, "null target unit in getThreats");
		if (Util::GetDpsForTarget(targetUnit, rangedUnit, m_bot) == 0.f)
			continue;
		//We consider a unit as a threat if the sum of its range and speed is bigger than the distance to our unit
		//But this is not working so well for melee units, we keep every units in a radius of min threat range
		float threatRange = getThreatRange(rangedUnit, targetUnit);
		if (Util::Dist(rangedUnit->pos, targetUnit->pos) < threatRange)
			threats.push_back(targetUnit);
	}

	return threats;
}