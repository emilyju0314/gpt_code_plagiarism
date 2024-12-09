ts::UString ts::UString::toHTML(const UString& convert) const
{
    UString result(*this);
    result.convertToHTML(convert);
    return result;
}