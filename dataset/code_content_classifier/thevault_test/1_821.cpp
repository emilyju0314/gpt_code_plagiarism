int Scanner::ScanIdentifier()
{
    // Copy the identifier into the token string.
    char * p = tokenStr;
    while ((isalnum(*pCursor) || (*pCursor == '_') || (*pCursor == '.') || (*pCursor == '$')) &&
           (p < (tokenStr + sizeof(tokenStr) - 1)))
    {
        *p++ = *pCursor++;
    }
    *p = '\0';

    // Check to see if the string is a reserved register name.
    if (((tokenStr[1] == '\0') && (strchr("ABCDEHLM", toupper(tokenStr[0])) != NULL)) ||
        (strcasecmp(tokenStr, "SP") == 0) || (strcasecmp(tokenStr, "PSW") == 0))
    {
        tokenType = T_REGISTER;
    }
    else
    {
        tokenType = T_IDENTIFIER;
    }
    tokenValue = 0;
    return tokenType;
}