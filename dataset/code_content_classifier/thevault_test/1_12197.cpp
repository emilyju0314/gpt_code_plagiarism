AZStd::sys_time_t GetTimeNowSecond()
    {
        AZStd::sys_time_t timeNowSecond;
        struct timespec ts;
        int result = clock_gettime(CLOCK_MONOTONIC_RAW, &ts);  // Similar to CLOCK_MONOTONIC, but provides access to a raw hardware-based time that is not subject to NTP adjustments.
        (void)result;
        AZ_Assert(result != -1, "clock_gettime error: %s\n", strerror(errno));
        timeNowSecond =  ts.tv_sec;
        return timeNowSecond;
    }