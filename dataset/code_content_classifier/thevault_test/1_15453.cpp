K2HTransManager* K2HTransManager::Get(void)
{
	static K2HTransManager	transman;							// singleton
	return &transman;
}