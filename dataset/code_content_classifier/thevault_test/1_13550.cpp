void TestPlugin::tearDown()
{
    // clear resources
    CPPUNIT_ASSERT(test::Factory::instance());
    test::Factory::instance()->reset();
    test::Factory::instance()->getResources()->initDevs();
    // stop all activity left
    m_dvbscheduler.stop();

    // clear channels
    m_stations.clear();
}