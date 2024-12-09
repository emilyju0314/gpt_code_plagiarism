void __msleep(int milisec)
{
    struct timespec req;// = {0};
    req.tv_sec = (time_t) milisec / 1000;
    req.tv_nsec = (milisec % 1000) * 1000000L;
    //nanosleep(&req, (struct timespec *)NULL);
    clock_nanosleep(CLOCK_REALTIME, 0, &req, NULL);
}