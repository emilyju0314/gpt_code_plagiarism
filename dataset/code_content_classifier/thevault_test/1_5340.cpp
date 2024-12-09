void ts::UString::ArgMixInContext::getFormatSize(size_t& size)
{
    if (IsDigit(*_fmt)) {
        // An decimal integer literal is present, decode it.
        size = 0;
        while (IsDigit(*_fmt)) {
            size = 10 * size + *_fmt++ - u'0';
        }
    }
    else if (*_fmt == u'*') {
        // The size field is taken from the argument list.
        ++_fmt;
        if (_arg != _end) {
            size = _arg->toInteger<size_t>();
            ++_arg;
        }
        else if (debugActive()) {
            debug(u"missing argument for %* specifier");
        }
    }
}