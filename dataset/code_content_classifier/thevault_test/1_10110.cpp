bool RTCPUtility::RTCPParserV2::ParseXrReceiverReferenceTimeItem(
    int block_length_4bytes) {
  const int kBlockLengthIn4Bytes = 2;
  const int kBlockLengthInBytes = kBlockLengthIn4Bytes * 4;
  const ptrdiff_t length = _ptrRTCPBlockEnd - _ptrRTCPData;
  if (block_length_4bytes != kBlockLengthIn4Bytes ||
      length < kBlockLengthInBytes) {
    _state = ParseState::State_TopLevel;
    EndCurrentBlock();
    return false;
  }

  _packet.XRReceiverReferenceTimeItem.NTPMostSignificant = *_ptrRTCPData++<<24;
  _packet.XRReceiverReferenceTimeItem.NTPMostSignificant+= *_ptrRTCPData++<<16;
  _packet.XRReceiverReferenceTimeItem.NTPMostSignificant+= *_ptrRTCPData++<<8;
  _packet.XRReceiverReferenceTimeItem.NTPMostSignificant+= *_ptrRTCPData++;

  _packet.XRReceiverReferenceTimeItem.NTPLeastSignificant = *_ptrRTCPData++<<24;
  _packet.XRReceiverReferenceTimeItem.NTPLeastSignificant+= *_ptrRTCPData++<<16;
  _packet.XRReceiverReferenceTimeItem.NTPLeastSignificant+= *_ptrRTCPData++<<8;
  _packet.XRReceiverReferenceTimeItem.NTPLeastSignificant+= *_ptrRTCPData++;

  _packetType = RTCPPacketTypes::kXrReceiverReferenceTime;
  _state = ParseState::State_XRItem;
  return true;
}