TlvIterator(const uint8_t *aBuffer, uint8_t aLength)
        : TlvIterator(reinterpret_cast<const NetworkDataTlv *>(aBuffer),
                      reinterpret_cast<const NetworkDataTlv *>(aBuffer + aLength))
    {
    }