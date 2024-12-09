void ModuleFactory::load(const std::string& id)
{
    try
    {
        // create module instance
        IModulePtr module = getModule4Start(id);
        BOOST_ASSERT(module);

        // before load this module we should load all it's dependency
        StringList deps = m_dependency.getDependency(id);
        for (StringList::iterator i = deps.begin(); i != deps.end(); i++)
        {
            load(*i);
        }

        // start the thread
        startModuleThread(module);

        // wait until it will be really started
        time_t timeout = 60; // FIXME!!!  add to somewhere
        module->waitStart(timeout);
    }
    catch(const std::exception& err)
    {
        m_factory->getSNMP()->sendTrap(snmp::MODULE_LOAD_FAILED,
                                       id);

        klk_log(KLKLOG_ERROR, "Failed to load module '%s': %s",
                id.c_str(),
                err.what());
        throw;
    }
}