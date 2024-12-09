bool MemoryFile::Forward(size_t numBytes)
    {
        uint8* newPos = m_currentPos + numBytes;
        if (newPos > (m_memoryStart + m_length))
        {
            return false;
        }

        m_currentPos = newPos;
        return true;
    }