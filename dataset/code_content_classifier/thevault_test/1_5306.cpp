::WCHAR* ts::UString::wc_str()
{
    assert(sizeof(::WCHAR) == sizeof(UChar));
    return reinterpret_cast<::WCHAR*>(const_cast<UChar*>(data()));
}