bool ModuleFactory::isLoaded(const std::string& id)
{
    try
    {
        BOOST_ASSERT(id.empty() == false);
        IModulePtr module = getModule(id);
        if (module == NULL)
            return false;

        BOOST_ASSERT(module);
        IThreadPtr thread =
            boost::dynamic_pointer_cast<IThread, IModule>(module);
        BOOST_ASSERT(thread);
        if (getScheduler()->isStarted(thread) == false)
            return false;
        // check that initialization part was passed
        return module->isStarted();
    }
    catch(const std::exception& err)
    {
        klk_log(KLKLOG_ERROR, "Error while checking module load state: %s",
                err.what());
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR,
                "Unknown exception while checking module load state");
    }

    return false;
}