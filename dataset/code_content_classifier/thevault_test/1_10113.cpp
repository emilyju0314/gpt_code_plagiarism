int NETEQTEST_RTPpacket::extractRED(int index, webrtc::WebRtcRTPHeader& red)
{
//
//  0                   1                    2                   3
//  0 1 2 3 4 5 6 7 8 9 0 1 2 3  4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |1|   block PT  |  timestamp offset         |   block length    |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |1|    ...                                                      |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |0|   block PT  |
// +-+-+-+-+-+-+-+-+
//

    parseHeader();

    uint8_t* ptr = payload();
    uint8_t* payloadEndPtr = ptr + payloadLen();
    int num_encodings = 0;
    int total_len = 0;

    while ((ptr < payloadEndPtr) && (*ptr & 0x80))
    {
        int len = ((ptr[2] & 0x03) << 8) + ptr[3];
        if (num_encodings == index)
        {
            // Header found.
            red.header.payloadType = ptr[0] & 0x7F;
            uint32_t offset = (ptr[1] << 6) + (ptr[2] >> 2);
            red.header.sequenceNumber = sequenceNumber();
            red.header.timestamp = timeStamp() - offset;
            red.header.markerBit = markerBit();
            red.header.ssrc = SSRC();
            return len;
        }
        ++num_encodings;
        total_len += len;
        ptr += 4;
    }
    if ((ptr < payloadEndPtr) && (num_encodings == index))
    {
        // Last header.
        red.header.payloadType = ptr[0] & 0x7F;
        red.header.sequenceNumber = sequenceNumber();
        red.header.timestamp = timeStamp();
        red.header.markerBit = markerBit();
        red.header.ssrc = SSRC();
        ++ptr;
        return payloadLen() - (ptr - payload()) - total_len;
    }
    return -1;
}