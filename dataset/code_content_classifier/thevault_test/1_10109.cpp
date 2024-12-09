bool
RTCPUtility::RTCPParserV2::ParseIJ()
{
    const ptrdiff_t length = _ptrRTCPBlockEnd - _ptrRTCPData;

    if (length < 4)
    {
        return false;
    }

    _ptrRTCPData += 4; // Skip header

    _packetType = RTCPPacketTypes::kExtendedIj;

    // State transition
    _state = ParseState::State_ExtendedJitterItem;
    return true;
}