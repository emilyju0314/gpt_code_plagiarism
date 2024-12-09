ts::UString ts::UString::toQuoted(UChar quoteCharacter, const UString& specialCharacters, bool forceQuote) const
{
    UString result(*this);
    result.quoted(quoteCharacter, specialCharacters, forceQuote);
    return result;
}