const std::string ModuleProcessor::getReceiverAppID(const std::string& msgid) const
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
                return (*mod)->getType() == klk::mod::APP ? (*mod)->getID() :
                    MODULE_COMMON_ID;
            }
        }
    }

    // FIXME!!! bad code
    BOOST_ASSERT(false);
    return MODULE_COMMON_ID;
}