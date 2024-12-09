void NodeMap::RemoveEntryByNameID(uint32 firstNameID)
    {
        const size_t entryIndex = FindEntryIndexByNameID(firstNameID);
        if (entryIndex == InvalidIndex)
        {
            return;
        }

        m_entries.erase(AZStd::next(begin(m_entries), entryIndex));
    }