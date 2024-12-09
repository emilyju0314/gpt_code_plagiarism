size_t NodeMap::FindEntryIndexByNameID(uint32 firstNameID) const
    {
        const auto foundEntry = AZStd::find_if(begin(m_entries), end(m_entries), [firstNameID](const MapEntry& entry)
        {
            return entry.m_firstNameId == firstNameID;
        });
        return foundEntry != end(m_entries) ? AZStd::distance(begin(m_entries), foundEntry) : InvalidIndex;
    }