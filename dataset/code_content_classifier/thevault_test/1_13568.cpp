void TestHTTPSrc::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);
    // now load the it
    m_modfactory->load(MODID);

    // add helper module
    this->addDebug<TestHelpModule>();
    // load helper module
    m_modfactory->load(test::HELP_MOD_ID);
}