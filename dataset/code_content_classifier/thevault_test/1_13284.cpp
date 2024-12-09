const double Usage::getCPUUsage()
{
    struct timeval current;
    if (gettimeofday(&current, NULL) < 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Error %d in gettimeofday(): %s",
                        errno, strerror(errno));
    }
    struct rusage usg;
    if (getrusage(m_who, &usg) < 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Error %d in getrusage(): %s",
                        errno, strerror(errno));
    }

    Locker lock(this);

    // calculate cpu
    struct timeval initial_cpu;
    timeradd(&m_last_usage.ru_utime, &m_last_usage.ru_stime, &initial_cpu);
    struct timeval final_cpu;
    timeradd(&usg.ru_utime, &usg.ru_stime, &final_cpu);
    struct timeval cpu;
    timersub(&final_cpu, &initial_cpu, &cpu);

    // calculate total
    struct timeval total;
    timersub(&current, &m_start_time, &total);

    // calculate result
    double res = timeval2Double(cpu)/timeval2Double(total);

    // Save current measurments for next run.
    // getrusage() is not very precise (typically .01 sec).
    // Short time periods generate innacurate information.
    // (taken from :
       /*
       ** SellaNMS
       ** $Id: trace.cxx,v 1.8 2006/01/25 06:21:34 sella Exp $
       ** Copyright (c) 2001-2005 Digital Genesis Software, LLC.
       ** All Rights Reserved.
       ** Released under the GPL Version 2 License.
       ** http://www.digitalgenesis.com
       */
    // )
    if (total.tv_sec > 30) // don't update very often
    {
        memcpy(&m_last_usage, &usg, sizeof(struct rusage));
        memcpy(&m_start_time, &current, sizeof(struct timeval));
    }

    return res;
}