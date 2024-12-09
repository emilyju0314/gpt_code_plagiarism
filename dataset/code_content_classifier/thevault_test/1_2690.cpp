void gjAPI::UtilSleep(const unsigned int iMs)
{
#if defined(_GJ_WINDOWS_)

    Sleep(iMs);

#else

    struct timespec oReq;

    oReq.tv_sec  = (iMs / 1000);
    oReq.tv_nsec = (iMs % 1000) * 1000000;

    nanosleep(&oReq, NULL);

#endif
}