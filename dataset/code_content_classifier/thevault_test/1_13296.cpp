void TestCLI::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // load adapter
    loadAdapter();
    sleep(2);

    m_modfactory->load(MODID);
}