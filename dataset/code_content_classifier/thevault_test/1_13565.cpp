void TestMpegts::loadModules()
{
    // load adapter first
    // this is necessary because the main module (streamer)
    // is derived from klk::launcher::app::Module that
    // requires adapter to be run in constructor
    loadAdapter();

    CPPUNIT_ASSERT(m_modfactory);
    // now load the transcoder
    m_modfactory->load(MODID);
}