void TestCLI::testInShow(const std::string& test, bool presence)
{
    // variables
    adapter::MessagesProtocol proto(test::Factory::instance());
    // test addition of known command
    IMessagePtr in = m_msgfactory->getMessage(IN_SHOW_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    // empty info
    cli::ParameterVector params;
    cli::Utils::setProcessParams(in, params);
    // not valid IP address
    IMessagePtr out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    const std::string response = out->getValue(msg::key::CLIRESULT);
    bool found = (response.find(test) != std::string::npos);
    if (presence)
    {
        CPPUNIT_ASSERT(found == true);
    }
    else
    {
        CPPUNIT_ASSERT(found == false);
    }
}