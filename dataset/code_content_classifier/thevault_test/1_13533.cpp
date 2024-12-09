void ConnectThreadContainer::sendConnectionData(const std::string& path,
                                                const BinaryData& data)
{
    if (m_stop.isStopped())
        return;

    BOOST_ASSERT(path.empty() == false);
    Locker lock(&m_lock);
    std::for_each(m_list.begin(), m_list.end(),
                  boost::bind(&ConnectThread::addData, _1,
                              boost::ref(path),
                              boost::ref(data)));
}