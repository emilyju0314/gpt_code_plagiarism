int Scanner::Init(const char * ln)
{
    // Save the original line for future calls to Next().
    strncpy(line, ln, sizeof(line));
    line[sizeof(line) - 1] = '\0';
    pCursor = line;

    // If the first column is non-white then it is a label.
    if (isalpha(*pCursor) || (*pCursor == '_'))
    {
        if (ScanIdentifier() == T_ERROR)
        {
            // Overwrite the error message from ScanIdentifier to read 'label'
            // instead of 'identifier'.
            Failure("Illegal character in label.  Must be alphanum or underscore.");
        }
        else
        {
            if ((*pCursor == ':') || isspace(*pCursor))
            {
                tokenType = T_LABEL;
                ++pCursor;
            }
            else
            {
                Failure("Label must end with ':' or space or tab character.");
            }
            tokenValue = 0;
        }
        return tokenType;
    }

    else if (!isspace(*pCursor) && (*pCursor != ';') && (*pCursor != '\0'))
    {
        return Failure("Illegal character in column 1.  Must be label, comment, or space. Found:", pCursor);
    }

    // No label and first character was space.  Return the first token.
    tokenType = T_IDENTIFIER;   // Arbitrary - set to non-ERROR and non-EOF.
    return Next();              // This will set tokenType.
}