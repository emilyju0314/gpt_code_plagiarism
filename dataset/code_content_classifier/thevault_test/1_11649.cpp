void null_bytes ( ::HANDLE file, ::DWORD from, ::DWORD to )
    {
            // Specify range.
        ::FILE_ZERO_DATA_INFORMATION zeros;
        ::ZeroMemory(&zeros, sizeof(zeros));
        zeros.FileOffset.QuadPart = from;
        zeros.BeyondFinalZero.QuadPart = to;
        
            // Make it free!
        ::DWORD returned = 0;
        const ::BOOL result = ::DeviceIoControl(
            file, FSCTL_SET_ZERO_DATA, &zeros, sizeof(zeros), 0, 0, &returned, 0
            );
        if ( result == FALSE ) {
            throw (Error(::GetLastError()));
        }
    }