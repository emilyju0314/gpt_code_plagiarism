void ts::SleepThread(MilliSecond delay)
{
#if defined(TS_WINDOWS)

    // Window implementation.
    ::Sleep(::DWORD(delay));

#else

    // POSIX implementation.
    ::timespec requested, remain;
    requested.tv_sec = time_t(delay / 1000); // seconds
    requested.tv_nsec = long((delay % 1000) * 1000000); // nanoseconds
    while (::nanosleep(&requested, &remain) < 0) {
        if (errno == EINTR) {
            // Interrupted by a signal. Wait again.
            requested = remain;
        }
        else {
            // Actual error
            throw ts::Exception(u"nanosleep error", errno);
        }
    }

#endif
}