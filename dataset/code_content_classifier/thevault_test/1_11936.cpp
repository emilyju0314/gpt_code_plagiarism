bool MemoryFile::WriteByte(const uint8 value)
    {
        Write(&value, 1);
        return true;
    }