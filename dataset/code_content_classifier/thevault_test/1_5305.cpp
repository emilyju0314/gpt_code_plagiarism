const ::WCHAR* ts::UString::wc_str() const
{
    assert(sizeof(::WCHAR) == sizeof(UChar));
    return reinterpret_cast<const ::WCHAR*>(data());
}