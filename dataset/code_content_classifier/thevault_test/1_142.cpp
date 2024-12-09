explicit LeaderBase(Instance &aInstance)
        : MutableNetworkData(aInstance, mTlvBuffer, 0, sizeof(mTlvBuffer))
    {
        Reset();
    }