int count ( ::SOCKET engine )
    {
        int count = 0;
        const int result = ::getsockopt(
                               engine, SOL_IRLMP, IRLMP_ENUMDEVICES, 0, &count
                           );
        if ( result == SOCKET_ERROR ) {
            UNCHECKED_WIN32C_ERROR(getsockopt,::WSAGetLastError());
        }
        return (count);
    }