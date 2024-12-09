void TestSNMP::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // load adapter first
    // this is necessary because the main module (streamer)
    // is derived from klk::launcher::app::Module that
    // requires adapter to be run in constructor
    loadAdapter();

    m_modfactory->load(MODID);
}