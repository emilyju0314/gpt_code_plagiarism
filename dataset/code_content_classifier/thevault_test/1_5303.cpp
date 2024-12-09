ts::UString::UString(const ::WCHAR* s, size_type count, const allocator_type& alloc) :
    UString(reinterpret_cast<const UChar*>(s), count, alloc)
{
    assert(sizeof(::WCHAR) == sizeof(UChar));
}