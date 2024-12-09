void TestDVB::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // add helper modules
    this->addDebug<TestHelpModule>();

    // load module
    m_modfactory->load(MODID);
    // load helper module
    m_modfactory->load(TEST_MOD_ID);

    // create devices
    createDevs();
}