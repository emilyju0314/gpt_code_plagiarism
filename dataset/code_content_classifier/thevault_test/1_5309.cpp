ts::UString ts::UString::FromUTF8(const std::string& utf8)
{
    UString str;
    str.assignFromUTF8(utf8);
    return str;
}