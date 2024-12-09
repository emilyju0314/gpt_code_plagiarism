void SetCommissionerId(const char *aCommissionerId)
    {
        uint16_t length = StringLength(aCommissionerId, sizeof(mCommissionerId));
        memcpy(mCommissionerId, aCommissionerId, length);
        SetLength(static_cast<uint8_t>(length));
    }