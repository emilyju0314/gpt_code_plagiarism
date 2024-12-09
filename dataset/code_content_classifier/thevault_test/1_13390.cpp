void TestCLI::testSetSource()
{
    test::printOut("\nDVB CLI test (set source command) ... ");

    IMessagePtr in =
        m_msgfactory->getMessage(SETSOURCE_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    IMessagePtr out;
    cli::ParameterVector params;
    // incorrect param number
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::FAILED);

    params.resize(1);
    params[0] = TESTCARD3;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::FAILED);

    // OK change
    testSource(TESTCARD3, TESTSOURCEINITIAL); // initial value
    params.clear();
    params.resize(2);
    params[0] = TESTCARD3;
    params[1] = TESTSOURCEFIN;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);
    testSource(TESTCARD3, TESTSOURCEFIN); // final value

    // Incorrect dev name
    params.clear();
    params.resize(2);
    params[0] = "incorrectdev";
    params[1] = TESTSOURCEFIN;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::FAILED);

    // Incorrect source name
    params.clear();
    params.resize(2);
    params[0] = TESTCARD3;
    params[1] = "incorrect source";
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::FAILED);
}