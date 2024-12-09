uint16 Actor::FindBestMatchForNode(const char* nodeName, const char* subStringA, const char* subStringB, bool firstPass) const
    {
        char newString[1024];
        AZStd::string nameA;
        AZStd::string nameB;

        // search through all nodes to find the best match
        const size_t numNodes = m_skeleton->GetNumNodes();
        for (size_t n = 0; n < numNodes; ++n)
        {
            // get the node name
            const char* name = m_skeleton->GetNode(n)->GetName();

            // check if a substring appears inside this node's name
            if (strstr(name, subStringB))
            {
                // remove the substrings from the names
                nameA = nodeName;
                nameB = name;

                uint32 offset = 0;
                char* stringData = nameA.data();
                MCore::MemSet(newString, 0, 1024 * sizeof(char));
                while (offset < nameA.size())
                {
                    // locate the substring
                    stringData = strstr(stringData, subStringA);
                    if (stringData == nullptr)
                    {
                        break;
                    }

                    // replace the substring
                    // replace subStringA with subStringB
                    offset = static_cast<uint32>(stringData - nameA.data());

                    azstrncpy(newString, 1024, nameA.c_str(), offset);
                    azstrcat(newString, 1024, subStringB);
                    azstrcat(newString, 1024, stringData + strlen(subStringA));

                    stringData += strlen(subStringA);

                    // we found a match
                    if (nameB == newString)
                    {
                        return static_cast<uint16>(n);
                    }
                }
            }
        }

        if (firstPass)
        {
            return FindBestMatchForNode(nodeName, subStringB, subStringA, false); // try it the other way around (substring wise)
        }
        // return the best match
        return MCORE_INVALIDINDEX16;
    }