void NodeMap::SetEntry(const char* firstName, const char* secondName, bool addIfNotExists)
    {
        // check if there is already an entry for this name
        const size_t entryIndex = FindEntryIndexByName(firstName);
        if (entryIndex == InvalidIndex)
        {
            // if there is no such entry yet, and we also don't want to add a new one, then there is nothing to do
            if (addIfNotExists == false)
            {
                return;
            }

            // add a new entry
            AddEntry(firstName, secondName);
            return;
        }

        // modify it
        SetSecondName(entryIndex, secondName);
    }