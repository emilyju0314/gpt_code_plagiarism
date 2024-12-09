::DWORD count ( ::UINT codepage, const char * value )
    {
        const int result = ::MultiByteToWideChar
            (codepage, 0, value, -1, 0, 0);
        if ( result == 0 ) {
            const ::DWORD error = ::GetLastError();
            UNCHECKED_WIN32C_ERROR(MultiByteToWideChar,error);
        }
        return (result);
    }