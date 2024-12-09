void Scheduler::stopThread(const IThreadPtr& thread)
{
    base::Scheduler::stopThread(thread);

    // clear DVB thread info
    Locker lock(&m_dvb_lock);
    m_dvb_threadinfo.remove_if(boost::bind(FindThreadByThread(), _1, thread));
}