uint16_t GetSedBufferSize(void) const
    {
        uint16_t buffersize = OPENTHREAD_CONFIG_DEFAULT_SED_BUFFER_SIZE;

        if (IsSedBufferingIncluded())
        {
            buffersize = HostSwap16(mSedBufferSize);
        }
        return buffersize;
    }