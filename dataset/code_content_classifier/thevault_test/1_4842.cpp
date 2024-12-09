void GameCommander::setValidUnits()
{
    // make sure the unit is completed and alive and usable
    //for (auto & unit : m_bot.UnitInfo().getUnits(Players::Self))
	for (auto & mapUnit : m_bot.GetAllyUnits())
    {
		auto &unit = mapUnit.second;
		if (!unit.isValid())
			continue;
		if (!unit.isCompleted())
			continue;
		if (!unit.isAlive())
			continue;
        m_validUnits.push_back(unit);
    }
}