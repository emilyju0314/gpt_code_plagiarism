AtlasCoordinates TextureAtlasImpl::GetAtlasCoordinates(const AZStd::string& handle) const
    {
        AZStd::string path = handle;
        path = path.substr(0, path.find_last_of('.'));
        // Use an iterator to check if the key is being used in the hash table
        auto iterator = m_data.find(path);
        if (iterator != m_data.end())
        {
            return iterator->second;
        }
        else
        {
            return AtlasCoordinates(-1, -1, -1, -1);
        }
    }