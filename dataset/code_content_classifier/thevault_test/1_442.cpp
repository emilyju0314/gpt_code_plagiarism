bool NetworkShutdown()
    {

    #ifdef WIN32
        /* Clean up Windows Sockets */
        int32_t ret = WSACleanup();

        if(ret != NO_ERROR)
        {
            debug::error("Windows socket cleanup failed (WSACleanup returned error ", ret, ") ");
            return false;
        }

    #endif

        debug::log(2, FUNCTION, "Network resource cleanup complete");

        return true;
    }