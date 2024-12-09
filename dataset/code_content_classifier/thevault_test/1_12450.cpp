bool DiskFile::Seek(size_t offset)
    {
        MCORE_ASSERT(m_file);

        if (fseeko(m_file, offset, SEEK_SET) != 0)
        {
            return false;
        }

        return true;
    }