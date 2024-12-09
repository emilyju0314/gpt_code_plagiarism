void encodeCompactInteger(const CompactInteger &value,
                              ScaleEncoderStream &out) {
      // cannot encode negative numbers
      // there is no description how to encode compact negative numbers
      if (value < 0) {
        base::raise(EncodeError::NEGATIVE_COMPACT_INTEGER);
      }

      if (value < compact::EncodingCategoryLimits::kMinUint16) {
        encodeFirstCategory(value.convert_to<uint8_t>(), out);
        return;
      }

      if (value < compact::EncodingCategoryLimits::kMinUint32) {
        encodeSecondCategory(value.convert_to<uint16_t>(), out);
        return;
      }

      if (value < compact::EncodingCategoryLimits::kMinBigInteger) {
        encodeThirdCategory(value.convert_to<uint32_t>(), out);
        return;
      }

      // number of bytes required to represent value
      size_t bigIntLength = countBytes(value);

      // number of bytes to scale-encode value
      // 1 byte is reserved for header
      size_t requiredLength = 1 + bigIntLength;

      if (bigIntLength > 67) {
        base::raise(EncodeError::COMPACT_INTEGER_TOO_BIG);
      }

      ByteArray result;
      result.reserve(requiredLength);

      /* The value stored in 6 major bits of header is used
       * to encode number of bytes for storing big integer.
       * Value formed by 6 bits varies from 0 to 63 == 2^6 - 1,
       * However big integer byte count starts from 4,
       * so to store this number we should decrease this value by 4.
       * And the range of bytes number for storing big integer
       * becomes 4 .. 67. To form resulting header we need to move
       * those bits representing bytes count to the left by 2 positions
       * by means of multiplying by 4.
       * Minor 2 bits store encoding option, in our case it is 0b11 == 3
       * We just add 3 to the result of operations above
       */
      uint8_t header = (bigIntLength - 4) * 4 + 3;

      result.push_back(header);

      CompactInteger v{value};
      for (size_t i = 0; i < bigIntLength; ++i) {
        result.push_back(static_cast<uint8_t>(
            v & 0xFF));  // push back least significant byte
        v >>= 8;
      }

      for (const uint8_t c : result) {
        out << c;
      }
    }