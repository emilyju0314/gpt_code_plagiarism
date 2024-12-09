::ATOM find ( ::LPCWSTR name )
    {
        const ::ATOM atom = ::FindAtomW(name);
        if ( atom == 0 )
        {
            const ::DWORD error = ::GetLastError();
            if ( error == ERROR_FILE_NOT_FOUND ) {
                return (gfind(name));
            }
            UNCHECKED_WIN32C_ERROR(FindAtom, ::GetLastError());
        }
        return (atom);
    }