uint8 MemoryFile::GetNextByte()
    {
        uint8 value = *m_currentPos;
        m_currentPos++;
        return value;
    }