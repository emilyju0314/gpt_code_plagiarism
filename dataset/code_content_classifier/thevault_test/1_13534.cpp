void ConnectThreadContainer::notifyStopConnectThread(
    const ConnectThread* thread)
{
    if (m_stop.isStopped())
        return;

    BOOST_ASSERT(thread);
    Locker lock(&m_lock);
    ConnectThreadList::iterator i =
        std::find_if(m_list.begin(), m_list.end(),
                     boost::bind(std::equal_to<std::string>(),
                                 thread->getUUID(),
                                 boost::bind(&ConnectThread::getUUID, _1)));
    if (i == m_list.end())
        return; // nothing to do

    // stop it
    getFactory()->getStopThread()->addConnectThread(*i);
    // some clearing
    m_list.erase(i);
}