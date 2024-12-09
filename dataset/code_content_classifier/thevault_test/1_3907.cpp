nlohmann::json World::sortJSONEntities(nlohmann::json nonSortedEntities)
{
	std::vector<nlohmann::json> sortedJsonEntities;
	nlohmann::json::iterator jsonEntitiesIterator;


	for (jsonEntitiesIterator = nonSortedEntities.begin(); jsonEntitiesIterator != nonSortedEntities.end(); jsonEntitiesIterator++) {
		bool individualSorted = false;
		if (sortedJsonEntities.size() == 0) {
			sortedJsonEntities.push_back(jsonEntitiesIterator.value());
		}
		else {
			for (auto it = sortedJsonEntities.begin(); individualSorted == false && it != sortedJsonEntities.end();) {
				if (jsonEntitiesIterator.value()["Order"] <= (*it)["Order"]) {
					sortedJsonEntities.insert(it, jsonEntitiesIterator.value());
					individualSorted = true;
				}
				else if (std::next(it,1) == sortedJsonEntities.end()) {
					sortedJsonEntities.push_back(jsonEntitiesIterator.value());
					individualSorted = true;
				}
				else {
					it++;
				}
			}
		}
	}
	
	return sortedJsonEntities;
}