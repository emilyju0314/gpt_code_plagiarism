int Scanner::ScanConstant()
{
    int base = 10;

    // Copy the constant into the token string.  Note that isxdigit is also
    // catching the 'B' and 'D' suffixes for decimal and binary.
    char * p = tokenStr;
    while ((isxdigit(*pCursor) || (toupper(*pCursor) == 'H')) &&
           (p < (tokenStr + sizeof(tokenStr) - 1)))
    {
        *p++ = *pCursor++;
    }
    *p = '\0';

    // Check the last character of the string for a base identifier.
    char c = toupper(*--p);
    if (c == 'H')
    {
        base = 16;
    }
    else if (c == 'B')
    {
        base = 2;
    }
    else if ((c == 'D') || isdigit(c))
    {
        // Decimal suffix is optional.
        base = 10;
    }
    else
    {
        // String ended with A, C, E, or F.  Probably hex with no suffix.
        return Failure("Bad numeric constant.  Hex constants must end with 'H'", tokenStr);
    }

    tokenType = T_CONSTANT;
    tokenValue = int(strtol(tokenStr, NULL, base));

    // Scan back thru the string and verify the characters all match the base.
    while (--p >= tokenStr)
    {
        if ((base == 10) && !isdigit(*p))
        {
            return Failure("Illegal character in decimal constant", tokenStr);
        }
        else if ((base == 2) && (*p != '0') && (*p != '1'))
        {
            return Failure("Illegal character in binary constant", tokenStr);
        }
        else if (!isxdigit(*p))
        {
            return Failure("Illegal character in hex constant", tokenStr);
        }
    }

    return tokenType;
}