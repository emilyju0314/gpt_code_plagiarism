void NodeMap::RemoveEntryByName(const char* firstName)
    {
        const size_t entryIndex = FindEntryIndexByName(firstName);
        if (entryIndex == InvalidIndex)
        {
            return;
        }

        m_entries.erase(AZStd::next(begin(m_entries), entryIndex));
    }