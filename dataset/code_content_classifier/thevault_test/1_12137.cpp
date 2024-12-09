void MCoreSystem::MemTempBufferAssureSize(size_t numBytes)
    {
        // if the buffer is already big enough, we can just return
        if (m_memTempBufferSize >= numBytes)
        {
            return;
        }

        // resize the buffer (make it bigger)
        m_memTempBuffer = Realloc(m_memTempBuffer, numBytes, MCORE_MEMCATEGORY_SYSTEM);
        MCORE_ASSERT(m_memTempBuffer);

        m_memTempBufferSize = numBytes;
    }