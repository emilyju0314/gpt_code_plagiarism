uint32_t GetEnterpriseNumber(void) const
    {
        return IsThreadEnterprise() ? static_cast<uint32_t>(kThreadEnterpriseNumber)
                                    : HostSwap32(mShared.mEnterpriseNumber);
    }