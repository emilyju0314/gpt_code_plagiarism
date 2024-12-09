NetworkData(Instance &aInstance, const NetworkDataTlv *aStartTlv, const NetworkDataTlv *aEndTlv)
        : InstanceLocator(aInstance)
        , mTlvs(reinterpret_cast<const uint8_t *>(aStartTlv))
        , mLength(static_cast<uint8_t>(reinterpret_cast<const uint8_t *>(aEndTlv) -
                                       reinterpret_cast<const uint8_t *>(aStartTlv)))
    {
    }