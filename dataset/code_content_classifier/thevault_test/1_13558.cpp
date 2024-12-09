void ModuleFactory::unload(const std::string& id)
{
    BOOST_ASSERT(id.empty() == false);
    // first of all look at the known modules list
    IModulePtr module = getModule(id);
    if (module == NULL)
    {
        // can be called during unloading dependencies
        // that can be not loaded
        klk_log(KLKLOG_ERROR, "Failed to unload module '%s'. "
                "The module does not exist.", id.c_str());
        return;
    }

    IThreadPtr thread =
        boost::dynamic_pointer_cast<IThread, IModule>(module);
    BOOST_ASSERT(thread);
    if (getScheduler()->isStarted(thread))
    {
        getScheduler()->stopThread(thread);
    }
    BOOST_ASSERT(getScheduler()->isStarted(thread) == false);
}