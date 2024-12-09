static uint16_t CalculateSize(uint32_t aEnterpriseNumber, uint8_t aServiceDataLength)
    {
        return sizeof(NetworkDataTlv) + kMinLength + aServiceDataLength +
               ((aEnterpriseNumber == kThreadEnterpriseNumber) ? 0 : sizeof(uint32_t) /* mEnterpriseNumber  */);
    }