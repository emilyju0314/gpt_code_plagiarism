void TestTaskCLI::testShow(const std::string& task, bool presence)
{
    // variables
    adapter::MessagesProtocol proto(klk::test::Factory::instance());
    // test addition of known command
    IMessagePtr in = m_msgfactory->getMessage(TASKSHOW_COMMAND_ID);
    CPPUNIT_ASSERT(in);
    cli::ParameterVector params;
    cli::Utils::setProcessParams(in, params);

    IMessagePtr out = proto.sendSync(in);
    CPPUNIT_ASSERT(out);
    CPPUNIT_ASSERT(out->getValue(msg::key::STATUS) == msg::key::OK);

    const std::string response = out->getValue(msg::key::CLIRESULT);
    bool found = (response.find(task) != std::string::npos);
    if (presence)
    {
        CPPUNIT_ASSERT(found == true);
    }
    else
    {
        CPPUNIT_ASSERT(found == false);
    }
}