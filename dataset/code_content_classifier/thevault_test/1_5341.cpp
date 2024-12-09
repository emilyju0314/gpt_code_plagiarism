ts::UString::ArgMixOutContext::ArgMixOutContext(size_t& extractedCount, const UChar*& input, const UChar*& fmt, const std::initializer_list<ArgMixOut>& args) :
    ArgMixContext(fmt, false),
    _input(input),
    _arg(args.begin()),
    _end(args.end())
{
    // Initialize output fields.
    extractedCount = 0;

    // Process all fields until end of any string or mismatch.
    do {
        // Skip spaces in input and format to point to next meaningful field.
        skipSpaces(_input);
        skipSpaces(_fmt);
    } while (*_input != CHAR_NULL && *_fmt != CHAR_NULL && processField());

    // Return updated pointers.
    extractedCount = _arg - args.begin();
    input = _input;
    fmt = _fmt;

    // Report extraneous parameters if the format has been completely parsed.
    if (*_fmt == CHAR_NULL && _arg != _end && debugActive()) {
        debug(u"extraneous " + Decimal(_end - _arg) + u" arguments");
    }
}