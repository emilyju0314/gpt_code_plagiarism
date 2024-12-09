uint8_t GetSedDatagramCount(void) const
    {
        uint8_t count = OPENTHREAD_CONFIG_DEFAULT_SED_DATAGRAM_COUNT;

        if (IsSedBufferingIncluded())
        {
            count = mSedDatagramCount;
        }
        return count;
    }