void ts::UString::format(const UChar* fmt, const std::initializer_list<ArgMixIn>& args)
{
    // Pre-reserve some space. We don't really know how much. Just address the most comman cases.
    reserve(256);

    // Process the string.
    ArgMixInContext ctx(*this, fmt, args);
}