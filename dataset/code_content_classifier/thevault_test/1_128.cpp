explicit NetworkData(Instance &aInstance, const uint8_t *aTlvs = nullptr, uint8_t aLength = 0)
        : InstanceLocator(aInstance)
        , mTlvs(aTlvs)
        , mLength(aLength)
    {
    }