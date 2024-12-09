bool StrategyManager::detectSupplyBlock(BuildOrderQueue & queue) const
{
	// Assume all is good if we're still in book
	if (!ProductionManager::Instance().isOutOfBook()) return false;

	// Count supply being built
	int supplyBeingBuilt = BuildingManager::Instance().numBeingBuilt(BWAPI::Broodwar->self()->getRace().getSupplyProvider()) * 16;

    // If supply is maxed, there is no block.
    if (BWAPI::Broodwar->self()->supplyTotal() + supplyBeingBuilt >= 400)
    {
        return false;
    }

	// Terran and protoss calculation:
	int supplyAvailable = BWAPI::Broodwar->self()->supplyTotal() - BWAPI::Broodwar->self()->supplyUsed() + supplyBeingBuilt;

	// Zerg calculation:
	// Zerg can create an overlord that doesn't count toward supply until the next check.
	// To work around it, add up the supply by hand, including hatcheries.
	if (BWAPI::Broodwar->self()->getRace() == BWAPI::Races::Zerg) {
		supplyAvailable = -BWAPI::Broodwar->self()->supplyUsed();
		for (auto & unit : BWAPI::Broodwar->self()->getUnits())
		{
			if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord)
			{
				supplyAvailable += 16;
			}
			else if (unit->getType() == BWAPI::UnitTypes::Zerg_Egg &&
				unit->getBuildType() == BWAPI::UnitTypes::Zerg_Overlord)
			{
				return false;    // supply is building, return immediately
				// supplyAvailable += 16;
			}
			else if ((unit->getType() == BWAPI::UnitTypes::Zerg_Hatchery && unit->isCompleted()) ||
				unit->getType() == BWAPI::UnitTypes::Zerg_Lair ||
				unit->getType() == BWAPI::UnitTypes::Zerg_Hive)
			{
				supplyAvailable += 2;
			}
		}
	}

    // Roughly estimate that 6 mineral workers will support constant production from a gateway
    // Then reserve enough supply to produce a unit out of each of these virtual gateways
    // This is a very rough estimate and doesn't take into consideration anything else we are building
    // At minimum keep a buffer of 16
    int supplyNeeded = std::max(
        (WorkerManager::Instance().getNumMineralWorkers() / 6) * 4,
        16);

	return supplyAvailable < supplyNeeded;
}