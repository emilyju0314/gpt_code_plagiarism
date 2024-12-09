explicit Local(Instance &aInstance)
        : MutableNetworkData(aInstance, mTlvBuffer, 0, sizeof(mTlvBuffer))
        , mOldRloc(Mac::kShortAddrInvalid)
    {
    }