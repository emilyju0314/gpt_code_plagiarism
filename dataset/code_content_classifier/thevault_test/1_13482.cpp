void TestService::loadModules()
{
    // remove prev. results
    base::Utils::unlink(srv::test::RESULTDIR);
    // create the empty folder for future tests
    base::Utils::mkdir(srv::test::RESULTDIR);

    // to be able use RPC for different objects
    loadAdapter();
    sleep(3);

    CPPUNIT_ASSERT(m_modfactory);
    m_modfactory->load(MODID);
}