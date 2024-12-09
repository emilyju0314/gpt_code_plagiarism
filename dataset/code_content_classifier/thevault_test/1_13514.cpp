void ModuleProcessor::handleModule(int fd, int argc, char *argv[],
                                   const char* command_name,
                                   const char* msgid,
                                   int modnameused)
{
    BOOST_ASSERT(command_name);
    BOOST_ASSERT(msgid);

    BOOST_ASSERT(m_factory->getMessageFactory());
    BOOST_ASSERT(m_factory->getModuleFactory());

    // retrives parameters
    ParameterVector commands = Utils::getCommands(command_name);
    cli::ParameterVector params;
    int startpos = static_cast<int>(commands.size());
    if (modnameused)
        startpos++;
    for (int i = startpos; i < argc; i++)
    {
        std::string value = argv[i];
        boost::trim_if(value, boost::is_any_of(" \r\n\t"));
        if (value.empty())
            break;
        params.push_back(value);
    }

    std::string cliresp;

    try
    {
        // check the module
        cli::ICommandPtr command = getCommandByMsgID(msgid);
        if (command->isRequireModule() == false)
        {
            cliresp = command->process(params);
        }
        else
        {
            IMessagePtr in = m_factory->getMessageFactory()->getMessage(msgid);
            BOOST_ASSERT(in);
            Utils::setProcessParams(in, params);

            const std::string receiver = getReceiverAppID(msgid);
            adapter::MessagesProtocol proto(m_factory, receiver);
            IMessagePtr out = proto.sendSync(in);
            BOOST_ASSERT(out);
            // check status
            if (out->getValue(msg::key::STATUS) != msg::key::OK)
            {
                cliresp = out->getValue(msg::key::ERROR);
            }
            else
            {
                cliresp = out->getValue(msg::key::CLIRESULT);
            }
        }
    }
    catch(Exception& err)
    {
        ast_cli(fd,
                "Failed to execute command\n"
		"No response from server or server not running.\n");
        throw err;
    }
    catch(boost::bad_lexical_cast&)
    {
        ast_cli(fd,
                "Failed to execute command\n"
		"Bad lexical cast.\n");
        throw Exception(__FILE__, __LINE__, err::BADLEXCAST);
    }
    catch(...)
    {
        ast_cli(fd,
                "Failed to execute command\n"
		"Unknown error\n");
        throw Exception(__FILE__, __LINE__, "Unknown error");
    }

    ast_cli(fd, "%s", cliresp.c_str());
    ast_cli(fd, "\n");

    // reload module specific info
    // we should load new modules if the appears after execution
    // of the command
    // FIXME!!! add the code (see ticket #111)
    update();
}