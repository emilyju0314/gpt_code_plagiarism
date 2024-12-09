gjDataItem* gjAPI::gjInterDataStore::GetDataItem(const std::string& sKey)
{
    // create new data store item
    if(!m_apDataItem.count(sKey))
    {
        gjData asDataItemData;
        asDataItemData["key"] = sKey;
        m_apDataItem[sKey] = new gjDataItem(asDataItemData, m_iType, m_pAPI);
    }

    return m_apDataItem.count(sKey) ? m_apDataItem[sKey] : NULL;
}