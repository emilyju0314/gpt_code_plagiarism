void gjAPI::gjInterDataStore::ClearCache()
{
    // delete data store items
    FOR_EACH(it, m_apDataItem)
        SAFE_DELETE(it->second)

    // clear container
    m_apDataItem.clear();
}