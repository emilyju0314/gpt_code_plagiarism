void GameCommander::setCombatUnits()
{
    for (auto & unit : m_validUnits)
    {
        BOT_ASSERT(unit.isValid(), "Have a null unit in our valid units\n");

        if (!isAssigned(unit) && unit.getType().isCombatUnit())
        {
			if (unit.getAPIUnitType() == sc2::UNIT_TYPEID::TERRAN_KD8CHARGE)
				continue;

            assignUnit(unit, m_combatUnits);
        }
    }
}