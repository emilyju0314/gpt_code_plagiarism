bool DiskFile::Forward(size_t numBytes)
    {
        MCORE_ASSERT(m_file);

        if (fseeko(m_file, numBytes, SEEK_CUR) != 0)
        {
            return false;
        }

        return true;
    }