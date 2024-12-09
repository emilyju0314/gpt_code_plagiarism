bool ts::DVBCharsetUTF8::canEncode(const UString& str, size_t start, size_t count) const
{
    // All characters and can always be encoded in UTF-8.
    return true;
}