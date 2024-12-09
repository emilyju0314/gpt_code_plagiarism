ts::UString::ArgMixInContext::ArgMixInContext(UString& result, const UChar* fmt, const std::initializer_list<ArgMixIn>& args) :
    ArgMixContext(fmt, true),
    _result(result),
    _arg(args.begin()),
    _end(args.end())
{
    // Loop into format, stop at each '%' sequence.
    while (*_fmt != CHAR_NULL) {

        // Locate the next '%' or end of string.
        const UChar* const start = _fmt;
        while (*_fmt != CHAR_NULL && *_fmt != u'%') {
            ++_fmt;
        }

        // Copy this literal sequence directly into the result.
        result.append(start, _fmt - start);

        // Process '%' sequence.
        if (*_fmt == u'%') {
            ++_fmt;
            processArg();
        }
    }

    // Report extraneous parameters.
    if (_arg != _end && debugActive()) {
        debug(u"extraneous " + Decimal(_end - _arg) + u" arguments");
    }
}