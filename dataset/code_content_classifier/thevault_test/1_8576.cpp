inline size_t to_size_t(int_fast64_t v) noexcept
{
    REALM_ASSERT_DEBUG(!util::int_cast_has_overflow<size_t>(v));
    return size_t(v);
}