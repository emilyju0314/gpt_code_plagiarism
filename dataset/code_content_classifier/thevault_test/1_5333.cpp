ts::UString::size_type ts::UString::toDVB(uint8_t*& buffer, size_t& size, size_type start, size_type count, const DVBCharset* charset) const
{
    // Skip degenerated cases where there is nothing to do.
    if (buffer == nullptr || size == 0 || start >= length()) {
        return 0;
    }

    // Try to encode using these charsets in order
    static const DVBCharset* const dvbEncoders[] = {
        &ts::DVBCharsetSingleByte::ISO_6937,     // default charset
        &ts::DVBCharsetSingleByte::ISO_8859_15,  // most european characters and Euro currency sign
        &ts::DVBCharsetUTF8::UTF_8,              // last chance, used when no other match
        nullptr                                  // end of list
    };

    // Look for a character set which can encode the string.
    if (charset == nullptr || !charset->canEncode(*this, start, count)) {
        for (size_type i = 0; dvbEncoders[i] != nullptr; ++i) {
            if (dvbEncoders[i]->canEncode(*this, start, count)) {
                charset = dvbEncoders[i];
                break;
            }
        }
    }
    if (charset == nullptr) {
        // Should not happen since UTF-8 can encode everything.
        return 0;
    }

    // Serialize the table code.
    const size_t codeSize = charset->encodeTableCode(buffer, size);

    // Encode the string.
    return codeSize + charset->encode(buffer, size, *this, start, count);
}