void TestCLI::testStat()
{
    test::printOut("\nHTTP streamer cli test (in info) ... ");

    // prepare
    setOutput();

    // initial data
    sleep(db::CHECKDBINTERVAL);
    testInShow(TESTNAME1, false);
    testInShow(TESTNAME2, false);
    testInShow(TESTSERVERNAME, false);

    IMessagePtr out, in;
    cli::ParameterVector params(3);
    adapter::MessagesProtocol proto(test::Factory::instance());

    // add two initial routes
    setInput();
    sleep(db::CHECKDBINTERVAL);
    testInShow(TESTNAME1, true);
    testInShow(TESTNAME2, true);
    testInShow(TESTSERVERNAME, false);

    // try to wrong add
    in = m_msgfactory->getMessage(IN_ADD_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    params[0] = TESTNAME1;
    params[1] = TESTPATH1;
    params[2] = "flv";
    cli::Utils::setProcessParams(in, params);
    out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::FAILED);

    // try valid del
    in = m_msgfactory->getMessage(IN_DEL_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    cli::ParameterVector del_params(1);
    del_params[0] = TESTNAME1;
    cli::Utils::setProcessParams(in, del_params);
    out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);
    sleep(db::CHECKDBINTERVAL + 3);
    // check result
    testInShow(TESTNAME1, false);
    testInShow(TESTNAME2, true);

    // try the add again
    in = m_msgfactory->getMessage(IN_ADD_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    params[0] = TESTNAME1;
    params[1] = TESTPATH1;
    params[2] = "flv";
    cli::Utils::setProcessParams(in, params);
    out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);
    sleep(db::CHECKDBINTERVAL + 3);
    // check result
    testInShow(TESTNAME1, true);
    testInShow(TESTNAME2, true);
}