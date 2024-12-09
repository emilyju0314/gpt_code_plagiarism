void NETEQTEST_RTPpacket::scramblePayload(void)
{
    parseHeader();

    for (size_t i = 0; i < _payloadLen; ++i)
    {
        _payloadPtr[i] = static_cast<uint8_t>(rand());
    }
}