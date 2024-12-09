::WORD * write ( ::WORD * position, const wchar_t * string )
    {
        while ( *position++ = static_cast<::WORD>(*string++) )
            ;
        return (position);
    }