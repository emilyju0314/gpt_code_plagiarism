bool Scheduler::isStarted(const IDevPtr& dev) const
{
    BOOST_ASSERT(dev);

    DVBThreadInfoList::const_iterator find =
        std::find_if(m_dvb_threadinfo.begin(),
                     m_dvb_threadinfo.end(),
                     boost::bind(FindThreadByDev(),_1, dev));
    return (find != m_dvb_threadinfo.end());
}