double StrategyManager::getProductionSaturation(BWAPI::UnitType producer) const
{
    // Look up overall count and idle count
    int numFacilities = 0;
    int idleFacilities = 0;
    for (const auto unit : BWAPI::Broodwar->self()->getUnits())
        if (unit->getType() == producer
            && unit->isCompleted()
            && unit->isPowered())
        {
            numFacilities++;
            if (unit->getRemainingTrainTime() < 12) idleFacilities++;
        }

    if (numFacilities == 0) return 0.0;

    return (double)(numFacilities - idleFacilities) / (double)numFacilities;
}