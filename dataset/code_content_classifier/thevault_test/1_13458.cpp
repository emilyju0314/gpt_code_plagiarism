void CLIAppTest::testComplete()
{
    printOut("\nCLIApp completion test ... ");

    CPPUNIT_ASSERT(m_factory != NULL);

    cli::ICommandPtr setcmd(new cli::AutostartSet("testmsgid1"));
    setcmd->setFactory(m_factory);
    setcmd->setModuleID(TEST_APP_ID);
    cli::ICommandPtr showcmd(new cli::AutostartShow("testmsgid2"));
    showcmd->setFactory(m_factory);
    showcmd->setModuleID(TEST_APP_ID);
    cli::ParameterVector params;

    params.clear();
    params.push_back(cli::AUTOSTARTSET_ON);
    cli::ParameterVector setparams;
    params = setcmd->getCompletion(setparams);
    CPPUNIT_ASSERT(params.size() == 2);
    setparams.push_back("aaa");
    params = setcmd->getCompletion(setparams);
    CPPUNIT_ASSERT(params.size() == 0);

    params.clear();
    setparams.clear();
    params = showcmd->getCompletion(setparams);
    CPPUNIT_ASSERT(params.size() == 0);
}