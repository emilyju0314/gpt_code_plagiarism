void CSMTP::decodeFromBase64(const std::string &encoding,
                                 std::string &decoding, std::uint32_t numberOfBytes)
    {
        int byteIndex{0};
        std::uint8_t byte1, byte2, byte3, byte4;
        if ((numberOfBytes == 0) || (numberOfBytes % 4))
        {
            return;
        }
        decoding.clear();
        numberOfBytes = (numberOfBytes / 4);
        while (numberOfBytes--)
        {
            byte1 = encoding[byteIndex++];
            byte2 = encoding[byteIndex++];
            byte3 = encoding[byteIndex++];
            byte4 = encoding[byteIndex++];
            byte1 = decodeChar(byte1);
            byte2 = decodeChar(byte2);
            if (byte3 == '=')
            {
                byte3 = 0;
                byte4 = 0;
            }
            else if (byte4 == '=')
            {
                byte3 = decodeChar(byte3);
                byte4 = 0;
            }
            else
            {
                byte3 = decodeChar(byte3);
                byte4 = decodeChar(byte4);
            }
            decoding.append(1, ((byte1 << 2) + ((byte2 & 0x30) >> 4)));
            decoding.append(1, (((byte2 & 0xf) << 4) + ((byte3 & 0x3c) >> 2)));
            decoding.append(1, (((byte3 & 0x3) << 6) + byte4));
        }
    }