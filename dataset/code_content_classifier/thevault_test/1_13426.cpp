const bool TestThread::isStream() const
{
    Locker lock(&m_lock);
    return (!m_stations.empty());
}