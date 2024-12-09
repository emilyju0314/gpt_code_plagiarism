void TestBase::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // create devices
    createDevs();

    // load adapter first
    // this is necessary because the main module (streamer)
    // is derived from klk::launcher::app::Module that
    // requires adapter to be run in constructor
    loadAdapter();

    // now load the streamer
    m_modfactory->load(MODID);

    // sets the test processor
    getModule<Streamer>(MODID)->m_dvb_scheduler.setThreadFactory(m_thrfactory);
}