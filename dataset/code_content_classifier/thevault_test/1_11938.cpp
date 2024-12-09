bool MemoryFile::Seek(size_t offset)
    {
        if (offset > m_length)
        {
            return false;
        }

        m_currentPos = m_memoryStart + offset;
        return true;
    }