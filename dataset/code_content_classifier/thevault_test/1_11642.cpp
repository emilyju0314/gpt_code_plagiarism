::ATOM gfind ( ::LPCWSTR name )
    {
        const ::ATOM atom = ::GlobalFindAtomW(name);
        if ( atom == 0 ) {
            UNCHECKED_WIN32C_ERROR(FindAtom, ::GetLastError());
        }
        return (atom);
    }