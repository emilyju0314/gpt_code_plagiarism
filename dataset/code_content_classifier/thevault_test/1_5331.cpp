ts::UString ts::UString::FromDVB(const uint8_t* dvb, size_type dvbSize, const DVBCharset* charset)
{
    // Null or empty buffer is a valid empty string.
    if (dvb == nullptr || dvbSize == 0) {
        return UString();
    }

    // Get the DVB character set code from the beginning of the string.
    uint32_t code = 0;
    size_type codeSize = 0;
    if (!DVBCharset::GetCharCodeTable(code, codeSize, dvb, dvbSize)) {
        return UString();
    }

    // Skip the character code.
    assert(codeSize <= dvbSize);
    dvb += codeSize;
    dvbSize -= codeSize;

    // Get the character set for this DVB string.
    if (code != 0 || charset == nullptr) {
        charset = DVBCharset::GetCharset(code);
    }
    if (charset == nullptr) {
        // Unsupported charset. Collect all ANSI characters, replace others by '.'.
        UString str(dvbSize, FULL_STOP);
        for (size_type i = 0; i < dvbSize; i++) {
            if (dvb[i] >= 0x20 && dvb[i] <= 0x7E) {
                str[i] = UChar(dvb[i]);
            }
        }
        return str;
    }
    else {
        // Convert the DVB string using the character set.
        UString str;
        charset->decode(str, dvb, dvbSize);
        return str;
    }
}