void TestPlugin::checkChannels()
{
    // more than one channel to stream should be here
    CPPUNIT_ASSERT(m_stations.size() > 1);

    std::for_each(m_stations.begin(), m_stations.end(), boost::bind(CheckChannel(), _1));
}