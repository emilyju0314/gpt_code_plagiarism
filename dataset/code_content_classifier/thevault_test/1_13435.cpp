bool MessageFactory::hasMessage(const std::string& id)
{
    klk::Locker lock(this);
    if (m_async_container.empty() == false)
    {
        ASyncMessageInfoMap::iterator i = m_async_container.find(id);
        if (i != m_async_container.end())
        {
            return true;
        }
    }
    if (m_sync_container.empty() == false)
    {
        SyncMessageInfoMap::iterator i = m_sync_container.find(id);
        if (i != m_sync_container.end())
        {
            return true;
        }
    }

    // not found
    return false;
}