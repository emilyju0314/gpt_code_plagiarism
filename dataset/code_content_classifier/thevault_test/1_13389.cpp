void TestCLI::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // load module
    m_modfactory->load(MODID);

    // create devices
    createDevs();

    // load adapter
    loadAdapter();
}