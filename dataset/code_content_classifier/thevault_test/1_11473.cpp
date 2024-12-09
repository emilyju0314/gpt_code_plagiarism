std::shared_ptr<char[]> CSFTP::getIoBuffer()
    {
        if (!m_ioBuffer)
        {
            setIoBufferSize(m_ioBufferSize);
        }
        return m_ioBuffer;
    }