const NetworkDataTlv *GetNext(void) const
    {
        return reinterpret_cast<const NetworkDataTlv *>(reinterpret_cast<const uint8_t *>(this) + sizeof(*this) +
                                                        mLength);
    }