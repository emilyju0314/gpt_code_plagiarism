const IStreamPtr Scheduler::getStream(const IDevPtr& dev) const
{
    BOOST_ASSERT(dev);

    Locker lock(&m_dvb_lock);
    DVBThreadInfoList::const_iterator find =
        std::find_if(m_dvb_threadinfo.begin(),
                     m_dvb_threadinfo.end(),
                     boost::bind(FindThreadByDev(),_1, dev));
    if (find == m_dvb_threadinfo.end())
    {
        throw Exception(
            __FILE__, __LINE__,
            "No any DVB stream started for dev with uuid: '%s'",
            dev->getStringParam(dev::UUID).c_str());
    }

    return (*find)->getStream();
}