void Scheduler::createStreamThread(const IDevPtr& dev)
{
    BOOST_ASSERT(dev);
    Locker lock(&m_dvb_lock);
    if (!isStarted(dev))
    {
        IThreadInfoPtr threadinfo =
            getThreadFactory()->createStreamThread(dev);
        BOOST_ASSERT(threadinfo);
        startThread(threadinfo->getThread());
        m_dvb_threadinfo.push_back(threadinfo);
    }
}