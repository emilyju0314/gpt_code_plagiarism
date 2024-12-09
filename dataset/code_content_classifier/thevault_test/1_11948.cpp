void NodeMap::FindSecondName(const char* firstName, AZStd::string* outString)
    {
        const size_t entryIndex = FindEntryIndexByName(firstName);
        if (entryIndex == InvalidIndex)
        {
            outString->clear();
            return;
        }

        *outString = GetSecondNameString(entryIndex);
    }