uint32 AnimGraphObjectData::Load(const uint8* dataBuffer)
    {
        if (dataBuffer)
        {
            MCore::MemCopy((uint8*)this, dataBuffer, sizeof(*this));
        }

        return sizeof(*this);
    }