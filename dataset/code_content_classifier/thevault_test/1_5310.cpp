void ts::UString::toUTF8(std::string& utf8) const
{
    // The maximum number of UTF-8 bytes is 3 times the number of UTF-16 codes.
    utf8.resize(3 * size());

    const UChar* inStart = data();
    char* outStart = const_cast<char*>(utf8.data());
    ConvertUTF16ToUTF8(inStart, inStart + size(), outStart, outStart + utf8.size());

    utf8.resize(outStart - utf8.data());
}