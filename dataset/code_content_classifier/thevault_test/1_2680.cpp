int gjAPI::gjInterDataStore::__CheckCache(gjDataItemMap* papOutput)
{
    // retrieve cached data store items
    if(!m_apDataItem.empty())
    {
        if(papOutput)
        {
            FOR_EACH(it, m_apDataItem)
                (*papOutput)[it->first] = it->second;
        }
        return GJ_OK;
    }
    return GJ_NO_DATA_FOUND;
}