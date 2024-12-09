bool ts::UString::ArgMixOutContext::processField()
{
    assert(*_fmt != CHAR_NULL);
    assert(*_input != CHAR_NULL);

    // Process literal characters.
    if (*_fmt != u'%' || _fmt[1] == u'%') {
        // Either not a '%' sequence or a '%%' meaning a literal '%'.
        if (*_input != *_fmt) {
            // Failed to match a literal character.
            return false;
        }
        else {
            // The literal character matched, advance pointers.
            ++_input;
            _fmt += *_fmt == '%' ? 2 : 1;
            return true;
        }
    }

    // The available '%' sequences are:
    // - %d : Matches an integer in decimal or hexadecimal.
    // - %x : Matches an integer in hexadecimal, case-insensitive, without 0x or 0X prefix.
    // - %X : Same as %x.
    // - %c : Matches the next non-space character. The Unicode code point is returned.
    // - %% : Matches a literal % (already done).
    // The allowed options, between the '%' and the letter are:
    //    ' : For decimal integer conversions, skip separators for groups of thousands.

    // Extract the command and set fmt to its final value, after the '%' sequence.
    bool skipSeparator = false;
    UChar cmd = *++_fmt;
    if (cmd == u'\'') {
        skipSeparator = true;
        cmd = *++_fmt;
    }
    if (cmd != CHAR_NULL) {
        ++_fmt;
    }

    // Process invalid '%' sequence.
    if (cmd != u'c' && cmd != u'd' && cmd != u'i' && cmd != u'x' && cmd != u'X') {
        if (debugActive()) {
            debug(u"invalid '%' sequence", cmd);
        }
        return false;
    }

    // Process missing argument.
    if (_arg == _end) {
        if (debugActive()) {
            debug(u"missing argument", cmd);
        }
        return false;
    }

    // Process incorrect argument (internal error, bug).
    if (!_arg->isOutputInteger()) {
        // This should never occur since ArgMixOut can be constructed only from pointer to integer.
        debug(u"internal error, scan() argument is not a pointer to integer");
        return false;
    }

    // Extract a character literal, return its Unicode code point.
    if (cmd == u'c') {
        (_arg++)->storeInteger(*_input++);
        return true;
    }

    // Extract an integer value.
    UString value;
    const UChar* const start = _input;

    if (cmd == u'x' || cmd == u'X') {
        // Extract an hexadecimal value, without prefix.
        while (IsHexa(*_input)) {
            _input++;
        }
        // Extract the hexadecimal value with an added prefix.
        value = u"0x";
    }
    else if (_input[0] == u'0' && (_input[1] == u'x' || _input[1] == u'X')) {
        // Extract an hexadecimal value with prefix.
        if (IsHexa(_input[2])) {
            _input += 3;
            while (IsHexa(*_input)) {
                _input++;
            }
        }
    }
    else {
        // Extract a decimal value.
        if (_input[0] == u'-' && IsDigit(_input[1])) {
            _input += 2;
        }
        while (IsDigit(*_input) || (skipSeparator && *_input == u',')) {
            _input++;
        }
    }

    // Process value not found, invalid input, not a programming error.
    if (_input == start) {
        // No hexa value found
        return false;
    }

    // Build the string to decode, preserve optional prefix we added.
    value.append(start, _input - start);
    if (skipSeparator) {
        value.remove(u',');
    }

    // Decode signed or usigned value. Use 64 bits in all cases.
    // Note the decoding should not fail since we already checked the syntax.
    if (_arg->isSigned()) {
        int64_t i = 0;
        value.toInteger(i);
        _arg->storeInteger(i);
    }
    else {
        uint64_t i = 0;
        value.toInteger(i);
        _arg->storeInteger(i);
    }

    // Finally, absorb the extracted argument.
    ++_arg;
    return true;
}