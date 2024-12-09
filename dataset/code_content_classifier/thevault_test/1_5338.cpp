bool ts::UString::scan(size_t& extractedCount, size_type& endIndex, const UChar* fmt, const std::initializer_list<ArgMixOut>& args) const
{
    // Process this string instance.
    const UChar* input = data();
    ArgMixOutContext ctx(extractedCount, input, fmt, args);

    // Compute the next index in the input string.
    endIndex = input - data();

    // Return true when both the input string and the format have been completely consumed.
    return *input == CHAR_NULL && *fmt == CHAR_NULL;
}