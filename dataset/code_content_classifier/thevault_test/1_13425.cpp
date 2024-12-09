bool TestThreadFactory::isStream(const std::string& channel)
{
    Locker lock(&m_lock);
    IStationList::iterator find =
        std::find_if(m_stations.begin(), m_stations.end(),
                     boost::bind(
                         std::equal_to<std::string>(),
                         channel,
                         boost::bind(&IStation::getChannelName, _1)));
    return (find != m_stations.end());
}