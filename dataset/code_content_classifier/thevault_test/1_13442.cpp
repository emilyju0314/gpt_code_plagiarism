const int Stream::getRate(struct klkstat_s& stat) const
{
    struct timeval current;
    if (gettimeofday(&current, NULL) < 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Error %d in gettimeofday(): %s",
                        errno, strerror(errno));
    }

    // calculate rate
    struct timeval diff;
    timersub(&current, &stat.lastupdate, &diff);

    int rate = 0;
    if (stat.count != 0)
    {
        if (diff.tv_sec <= 0 && diff.tv_usec <= 0)
        {
            // cannot calculate rate
            throw Exception(__FILE__, __LINE__, "Incorrect time diff");
        }

        double time = diff.tv_sec + diff.tv_usec * 1.0e-6;
        BOOST_ASSERT(time > 0);
        rate = static_cast<int>(stat.count/time);
    }
    // clear rate info
    stat.count = 0;
    stat.lastupdate = current;

    return rate;
}