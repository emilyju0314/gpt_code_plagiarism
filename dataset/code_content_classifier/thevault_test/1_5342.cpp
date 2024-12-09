void ts::UString::ArgMixOutContext::skipSpaces(const UChar*& s)
{
    while (IsSpace(*s)) {
        ++s;
    }
}