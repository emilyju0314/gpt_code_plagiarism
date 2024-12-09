const cli::ICommandPtr
ModuleProcessor::getCommandByMsgID(const std::string& msgid)
{
    ModuleList modules =
        m_factory->getModuleFactory()->getModules();
    for (ModuleList::iterator mod = modules.begin();
         mod != modules.end(); mod++)
    {
        cli::ICommandList list = (*mod)->getCLIInfo();
        for (cli::ICommandList::iterator j = list.begin();
             j != list.end(); j++)
        {
            if ((*j)->getMessageID() == msgid)
            {
                return *j;
            }
        }
    }

    // FIXME!!! bad code
    BOOST_ASSERT(false);
    return cli::ICommandPtr();
}