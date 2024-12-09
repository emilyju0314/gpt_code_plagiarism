void StrategyManager::initializeOpening()
{
	auto buildOrderItr = _strategies.find(Config::Strategy::StrategyName);

	if (buildOrderItr != std::end(_strategies))
	{
		_openingGroup = (*buildOrderItr).second._openingGroup;
	}

    // Is the build a rush build?
    _rushing = 
        Config::Strategy::StrategyName == "9-9Gate" ||
        Config::Strategy::StrategyName == "9-9GateDefensive" ||
        Config::Strategy::StrategyName == "Proxy9-9Gate";

    if (_rushing) Log().Get() << "Enabled rush mode";
}