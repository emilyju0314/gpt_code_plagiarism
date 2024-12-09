bool TestThreadFactory::empty() const
{
    Locker lock(&m_lock);
    return m_stations.empty();
}