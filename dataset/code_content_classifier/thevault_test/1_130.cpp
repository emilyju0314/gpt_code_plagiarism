MutableNetworkData(Instance &aInstance, uint8_t *aTlvs, uint8_t aLength, uint8_t aSize)
        : NetworkData(aInstance, aTlvs, aLength)
        , mSize(aSize)
    {
    }