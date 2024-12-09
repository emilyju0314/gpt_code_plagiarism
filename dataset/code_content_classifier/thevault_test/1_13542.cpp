void TestNetwork::loadModules()
{
    CPPUNIT_ASSERT(m_modfactory);

    // create necessary dev
    createDev();

    // load the network module
    m_modfactory->load(MODID);

    // add helper module
    this->addDebug<TestHelpModule>();


    // load helper module
    m_modfactory->load(test::HELP_MOD_ID);
}