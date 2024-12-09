void CSMTP::encodeToBase64(const std::string &decoding,
                               std::string &encoding, std::uint32_t numberOfBytes)
    {
        int trailing, byteIndex = 0;
        std::uint8_t byte1, byte2, byte3;
        if (numberOfBytes == 0)
        {
            return;
        }
        encoding.clear();
        trailing = (numberOfBytes % 3); // Trailing bytes
        numberOfBytes /= 3;             // No of 3 byte values to encode
        while (numberOfBytes--)
        {
            byte1 = decoding[byteIndex++];
            byte2 = decoding[byteIndex++];
            byte3 = decoding[byteIndex++];
            encoding.append(1, kCB64[(byte1 & 0xfc) >> 2]);
            encoding.append(1, kCB64[((byte1 & 0x03) << 4) + ((byte2 & 0xf0) >> 4)]);
            encoding.append(1, kCB64[((byte2 & 0x0f) << 2) + ((byte3 & 0xc0) >> 6)]);
            encoding.append(1, kCB64[byte3 & 0x3f]);
        }
        // One trailing byte
        if (trailing == 1)
        {
            byte1 = decoding[byteIndex++];
            encoding.append(1, kCB64[(byte1 & 0xfc) >> 2]);
            encoding.append(1, kCB64[((byte1 & 0x03) << 4)]);
            encoding.append(1, '=');
            encoding.append(1, '=');
            // Two trailing bytes
        }
        else if (trailing == 2)
        {
            byte1 = decoding[byteIndex++];
            byte2 = decoding[byteIndex++];
            encoding.append(1, kCB64[(byte1 & 0xfc) >> 2]);
            encoding.append(1, kCB64[((byte1 & 0x03) << 4) + ((byte2 & 0xf0) >> 4)]);
            encoding.append(1, kCB64[((byte2 & 0x0f) << 2)]);
            encoding.append(1, '=');
        }
    }