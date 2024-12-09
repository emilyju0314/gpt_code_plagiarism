void ts::UString::ConvertUTF16ToUTF8(const UChar*& inStart, const UChar* inEnd, char*& outStart, char* outEnd)
{
    uint32_t code;
    uint32_t high6;

    while (inStart < inEnd && outStart < outEnd) {

        // Get current code point as 16-bit value.
        code = *inStart++;

        // Get the higher 6 bits of the 16-bit value.
        high6 = code & 0xFC00;

        // The possible ranges are:
        // - 0x0000-0x0xD7FF : direct 16-bit code point.
        // - 0xD800-0x0xDBFF : leading surrogate, first part of a surrogate pair.
        // - 0xDC00-0x0xDFFF : trailing surrogate, second part of a surrogate pair,
        //                     invalid and ignored if encountered as first value.
        // - 0xE000-0x0xFFFF : direct 16-bit code point.

        if (high6 == 0xD800) {
            // This is a "leading surrogate", must be followed by a "trailing surrogate".
            if (inStart >= inEnd) {
                // Invalid truncated input string, stop here.
                break;
            }
            // A surrogate pair always gives a code point value over 0x10000.
            // This will be encoded in UTF-8 using 4 bytes, check that we have room for it.
            if (outStart + 4 > outEnd) {
                inStart--;  // Push back the leading surrogate into the input buffer.
                break;
            }
            // Get the "trailing surrogate".
            const uint32_t surr = *inStart++;
            // Ignore the code point if the leading surrogate is not in the valid range.
            if ((surr & 0xFC00) == 0xDC00) {
                // Rebuild the 32-bit value of the code point.
                code = 0x010000 + (((code - 0xD800) << 10) | (surr - 0xDC00));
                // Encode it as 4 bytes in UTF-8.
                outStart[3] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[2] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[1] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[0] = char(0xF0 | (code & 0x07));
                outStart += 4;
            }
        }

        else if (high6 != 0xDC00) {
            // The 16-bit value is the code point.
            if (code < 0x0080) {
                // ASCII compatible value, one byte encoding.
                *outStart++ = char(code);
            }
            else if (code < 0x800 && outStart + 1 < outEnd) {
                // 2 bytes encoding.
                outStart[1] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[0] = char(0xC0 | (code & 0x1F));
                outStart += 2;
            }
            else if (code >= 0x800 && outStart + 2 < outEnd) {
                // 3 bytes encoding.
                outStart[2] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[1] = char(0x80 | (code & 0x3F));
                code >>= 6;
                outStart[0] = char(0xE0 | (code & 0x0F));
                outStart += 3;
            }
            else {
                // There not enough space in the output buffer.
                inStart--;  // Push back the leading surrogate into the input buffer.
                break;
            }
        }
    }
}