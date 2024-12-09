bool ProductionManager::meetsReservedResourcesWithExtra(const MetaType & type)
{
	assert("Addons cannot use extra ressources",m_bot.Data(type).isAddon);
	return (m_bot.Data(type).mineralCost <= getFreeMinerals() + getExtraMinerals()) && (m_bot.Data(type).gasCost <= getFreeGas() + getExtraGas());
}