TiXmlString::TiXmlString (const char* instring)
{
    size_t newlen;
    char * newstring;

    if (!instring)
    {
        allocated = 0;
        cstring = NULL;
        current_length = 0;
        return;
    }
    newlen = strlen (instring) + 1;
    newstring = new char [newlen];
    memcpy (newstring, instring, newlen);
    // strcpy (newstring, instring);
    allocated = newlen;
    cstring = newstring;
    current_length = newlen - 1;
}