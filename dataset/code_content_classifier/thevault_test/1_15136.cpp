BOOLEAN IsTownFound(INT8 const bTownID)
{
	auto town = GCM->getTown(bTownID);
	if (!town)
	{
		STLOGW("Town #{} not found", bTownID);
		return FALSE;
	}

	if (isSecretFound.find(town->getBaseSector()) == isSecretFound.end())
	{
		// town is always known to the player
		return TRUE;
	}

	return IsSecretFoundAt(town->getBaseSector());
}