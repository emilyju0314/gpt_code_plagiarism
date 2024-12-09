void TestCLI::testInfo()
{
    test::printOut("\nDVB CLI test (info command) ... ");

    IMessagePtr in =
        m_msgfactory->getMessage(INFO_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    IMessagePtr out;

    // OK get  usage info with possible adapter value
    // empty info this sets CLI type for processing
    cli::ParameterVector params;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    // OK get info for 0 adapter
    params.resize(1);
    params[0] = TESTCARD1;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    // OK get info for 1 adapter
    params[0] = TESTCARD2;
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    // not valid adapter number
    params[0] = "card111";
    cli::Utils::setProcessParams(in, params);
    out = m_proto->sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);
}