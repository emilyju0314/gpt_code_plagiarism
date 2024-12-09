void ts::UString::ConvertUTF8ToUTF16(const char*& inStart, const char* inEnd, UChar*& outStart, UChar* outEnd)
{
    uint32_t code;

    while (inStart < inEnd && outStart < outEnd) {

        // Get current code point at 8-bit value.
        code = *inStart++ & 0xFF;

        // Process potential continuation bytes and rebuild the code point.
        // Note: to speed up the processing, we do not check that continuation bytes,
        // if any, match the binary pattern 10xxxxxx.

        if (code < 0x80) {
            // 0xxx xxxx, ASCII compatible value, one byte encoding.
            *outStart++ = uint16_t(code);
        }
        else if ((code & 0xE0) == 0xC0) {
            // 110x xxx, 2 byte encoding.
            if (inStart >= inEnd) {
                // Invalid truncated input string, stop here.
                break;
            }
            else {
                *outStart++ = uint16_t((code & 0x1F) << 6) | (*inStart++ & 0x3F);
            }
        }
        else if ((code & 0xF0) == 0xE0) {
            // 1110 xxxx, 3 byte encoding.
            if (inStart + 1 >= inEnd) {
                // Invalid truncated input string, stop here.
                inStart = inEnd;
                break;
            }
            else {
                *outStart++ = uint16_t((code & 0x0F) << 12) | uint16_t((uint16_t(inStart[0] & 0x3F)) << 6) | (inStart[1] & 0x3F);
                inStart += 2;
            }
        }
        else if ((code & 0xF8) == 0xF0) {
            // 1111 0xxx, 4 byte encoding.
            if (inStart + 2 >= inEnd) {
                // Invalid truncated input string, stop here.
                inStart = inEnd;
                break;
            }
            else if (outStart + 1 >= outEnd) {
                // We need 2 16-bit values in UTF-16.
                inStart--;  // Push back the leading byte into the input buffer.
                break;
            }
            else {
                code = ((code & 0x07) << 18) | ((uint32_t(inStart[0] & 0x3F)) << 12) | ((uint32_t(inStart[1] & 0x3F)) << 6) | (inStart[2] & 0x3F);
                inStart += 3;
                code -= 0x10000;
                *outStart++ = uint16_t(0xD800 + (code >> 10));
                *outStart++ = uint16_t(0xDC00 + (code & 0x03FF));
            }
        }
        else {
            // 10xx xxxx, continuation byte, invalid here, simply ignore it.
            // 1111 1xxx, an invalid UTF-8 value, ignore as well.
            assert((code & 0xC0) == 0x80 || (code & 0xF8) == 0xF8);
        }
    }
}