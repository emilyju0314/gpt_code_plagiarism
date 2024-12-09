AZStd::sys_time_t GetTimeNowSecond()
    {
        AZStd::sys_time_t timeNowSecond;
        timeNowSecond =  GetTimeNowTicks()/GetTimeTicksPerSecond();
        return timeNowSecond;
    }