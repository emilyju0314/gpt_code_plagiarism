bool MemoryFile::Open(uint8* memoryStart, size_t length)
    {
        m_memoryStart    = memoryStart;
        m_currentPos     = memoryStart;
        m_length         = length;
        m_usedLength     = length;
        m_preAllocSize   = 1024; // pre-allocate 1 extra KB

        // if we need to create a new memory block
        if (memoryStart == nullptr)
        {
            m_allocate = true;
            if (length > 0)
            {
                m_memoryStart = (uint8*)MCore::Allocate(length, MCORE_MEMCATEGORY_MEMORYFILE);
                m_currentPos  = m_memoryStart;
            }
        }
        else
        {
            m_allocate = false;
        }

        return true;
    }