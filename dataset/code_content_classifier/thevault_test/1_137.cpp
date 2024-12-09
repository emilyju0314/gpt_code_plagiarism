bool IsValid(void) const
    {
        uint8_t length = GetLength();

        return (length >= sizeof(mFlagsServiceId)) &&
               (length >= kMinLength + (IsThreadEnterprise() ? 0 : sizeof(uint32_t))) &&
               (static_cast<uint16_t>(length) + sizeof(NetworkDataTlv) >=
                CalculateSize(GetEnterpriseNumber(), GetServiceDataLength()));
    }