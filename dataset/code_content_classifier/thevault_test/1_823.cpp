int Scanner::ScanString()
{
    bool bEscape = false;
    unsigned char c;
    const char * pStr = pCursor;
    char quote = *pCursor++;

    tokenLen = 0;
    tokenType = T_STRING;
    tokenValue = 0;

    while (*pCursor != '\0')
    {
        if (bEscape)
        {
            if (*pCursor == 'n')
            {
                c = '\n';
            }
            else if (*pCursor == 'r')
            {
                c = '\r';
            }
            else if (*pCursor == 't')
            {
                c = '\t';
            }
            else if (*pCursor == '0')
            {
                c = '\0';
            }
            else if (*pCursor == 'x')
            {
                if (isxdigit(pCursor[1]) && isxdigit(pCursor[2]))
                {
                    c = (HexDigit(*++pCursor) << 4);
                    c |= HexDigit(*++pCursor);
                }
                else
                {
                    return Failure("Bad hex escape in string", pCursor);
                }
            }
            else
            {
                // Any other character following a '\' just returns itself.
                // This also covers the special cases of \", \', and \\ to
                // return quotes and \ within a string.
                c = *pCursor;
            }
            bEscape = false;
        }
        else if (*pCursor == '\\')
        {
            bEscape = true;
            ++pCursor;
            continue;
        }
        else if (*pCursor == quote)
        {
            break;
        }
        else
        {
            c = *pCursor;
        }
        tokenStr[tokenLen++] = (char) c;
        ++pCursor;
    }

    if (*pCursor != quote)
    {
        return Failure("Unterminated string", pStr);
    }

    // Skip the trailing quote.
    ++pCursor;

    return tokenType;
}