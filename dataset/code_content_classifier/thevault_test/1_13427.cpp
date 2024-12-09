void TestSNMP::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // create devices
    createDevs();

    // load module
    m_modfactory->load(MODID);

    // wait for awhile
    sleep(2);
}