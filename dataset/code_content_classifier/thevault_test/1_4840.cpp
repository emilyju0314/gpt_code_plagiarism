void ProductionManager::create(const Unit & producer, BuildOrderItem & item, CCTilePosition position)
{
    if (!producer.isValid())
    {
        return;
    }

    // if we're dealing with a building
    if (item.type.isBuilding())
    {
        if (item.type.getUnitType().isMorphedBuilding())
        {
            producer.morph(item.type.getUnitType());
        }
        else
        {
			if (position.x == 0 && position.y == 0)
			{
				position = Util::GetTilePosition(m_bot.GetStartLocation());
			}
			m_bot.Buildings().addBuildingTask(item.type.getUnitType(), position);
        }
    }
    // if we're dealing with a non-building unit
    else if (item.type.isUnit())
    {
        producer.train(item.type.getUnitType());
    }
    else if (item.type.isUpgrade())
    {
		Micro::SmartAbility(producer.getUnitPtr(), m_bot.Data(item.type.getUpgrade()).buildAbility, m_bot);
    }
}