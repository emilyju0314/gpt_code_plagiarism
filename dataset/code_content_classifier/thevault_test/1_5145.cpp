void ts::TablesFactory::getRegisteredTableIds(std::vector<TID>& ids) const
{
    ids.clear();
    for (std::map<TID,TableFactory>::const_iterator it = _tableIds.begin(); it != _tableIds.end(); ++it) {
        ids.push_back(it->first);
    }
}