void TestFireWire::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);
    // now load the it
    m_modfactory->load(MODID);

    // add helper module
    this->addDebug<TestHelpModule>();
    m_modfactory->load(TEST_MOD_ID);

}