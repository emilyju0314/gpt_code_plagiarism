void TestCLI::testStatShow(const std::string& test, bool presence)
{
    // variables
    adapter::MessagesProtocol proto(test::Factory::instance());
    // test addition of known command
    IMessagePtr in = m_msgfactory->getMessage(STAT_COMMAND_ID);
    CPPUNIT_ASSERT(in);

    // input test
    cli::ParameterVector params(1);
    params[0] = STAT_COMMAND_PARAM_INPUT;
    cli::Utils::setProcessParams(in, params);
    IMessagePtr out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    std::string response = out->getValue(msg::key::CLIRESULT);
    bool found = (response.find(test) != std::string::npos);
    if (presence)
    {
        CPPUNIT_ASSERT(found == true);
    }
    else
    {
        CPPUNIT_ASSERT(found == false);
    }


    // output test
    params[0] = STAT_COMMAND_PARAM_OUTPUT;
    cli::Utils::setProcessParams(in, params);

    out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    response = out->getValue(msg::key::CLIRESULT);
    found = (response.find(test) != std::string::npos);
    if (presence)
    {
        CPPUNIT_ASSERT(found == true);
    }
    else
    {
        CPPUNIT_ASSERT(found == false);
    }

}