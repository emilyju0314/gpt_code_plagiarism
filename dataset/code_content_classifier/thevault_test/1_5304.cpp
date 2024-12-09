ts::UString::UString(const ::WCHAR* s, const allocator_type& alloc) :
    UString(s == 0 ? &CHAR_NULL : reinterpret_cast<const UChar*>(s), alloc)
{
    assert(sizeof(::WCHAR) == sizeof(UChar));
}