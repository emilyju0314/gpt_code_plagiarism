void SetAdvData(const uint8_t *aAdvData, uint8_t aAdvDataLength)
    {
        OT_ASSERT((aAdvData != nullptr) && (aAdvDataLength > 0) && (aAdvDataLength <= kAdvDataMaxLength));

        SetLength(aAdvDataLength + sizeof(mOui));
        memcpy(mAdvData, aAdvData, aAdvDataLength);
    }