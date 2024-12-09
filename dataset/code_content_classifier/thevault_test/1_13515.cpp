const ParameterVector ModuleProcessor::getCompletion(const std::string& line,
                                                     const std::string& word,
                                                     int pos,
                                                     const char* msgid)
{
    BOOST_ASSERT(msgid);
    ParameterVector result;

    cli::ICommandPtr command = getCommandByMsgID(msgid);

    // recalculate position
    ParameterVector command_names = base::Utils::split(command->getName(), " ");
    ParameterVector line_names = base::Utils::split(line, " ");

    ParameterVector setparams;
    BOOST_ASSERT(command_names.size() <= line_names.size());
    BOOST_ASSERT(static_cast<size_t>(pos) <= line_names.size());

    for (size_t i = 0; i < static_cast<size_t>(pos); i++)
    {
        // command names + module name
        if (i > command_names.size())
        {
            setparams.push_back(line_names[i]);
        }
    }

    if (command->isRequireModule() == false)
    {
        result = command->getCompletion(setparams);
    }
    else
    {
        IMessagePtr in = m_factory->getMessageFactory()->getMessage(msgid);
        BOOST_ASSERT(in);
        Utils::setCompletionRequest(in, setparams);

        const std::string receiver = getReceiverAppID(msgid);
        adapter::MessagesProtocol proto(m_factory, receiver);
        IMessagePtr out = proto.sendSync(in);
        BOOST_ASSERT(out);
        // check status
        if (out->getValue(msg::key::STATUS) != msg::key::OK)
        {
            throw Exception(__FILE__, __LINE__,
                            "Got a completion error: " +
                            out->getValue(msg::key::ERROR));
        }
        result = Utils::getCompletionResponse(out);
    }

    return result;
}