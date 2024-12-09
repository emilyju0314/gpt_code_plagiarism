size_t NodeMap::FindEntryIndexByName(const char* firstName) const
    {
        const auto foundEntry = AZStd::find_if(begin(m_entries), end(m_entries), [firstName](const MapEntry& entry)
        {
            return MCore::GetStringIdPool().GetName(entry.m_firstNameId) == firstName;
        });
        return foundEntry != end(m_entries) ? AZStd::distance(begin(m_entries), foundEntry) : InvalidIndex;
    }