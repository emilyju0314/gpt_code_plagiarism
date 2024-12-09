void Processor::registerCLI(const cli::ICommandPtr& command)

{
    BOOST_ASSERT(command);

    Locker lock(this); //FIXME!!! is it necessary?

    // should be unique
    cli::ICommandList::iterator i =
        std::find_if(m_clicommands.begin(), m_clicommands.end(),
                     boost::bind(std::equal_to<std::string>(),
                                 boost::bind(&cli::ICommand::getName,
                                             command),
                                 boost::bind(&cli::ICommand::getName,
                                             _1)));
    if (i != m_clicommands.end())
    {
        throw Exception(__FILE__, __LINE__,
                             "Command with name '%s' "
                             "has been already registered",
                             command->getName().c_str());

    }

    // insert at the end
    m_clicommands.push_back(command);

    // create a processor
    SyncFunction func = boost::bind(&Processor::processCLI,
                                    this, _1, _2);
    // register it
    registerSync(command->getMessageID(), func);
}