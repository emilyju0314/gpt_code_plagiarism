const char* NodeMap::FindSecondName(const char* firstName) const
    {
        const size_t entryIndex = FindEntryIndexByName(firstName);
        if (entryIndex == InvalidIndex)
        {
            return nullptr;
        }

        return GetSecondName(entryIndex);
    }