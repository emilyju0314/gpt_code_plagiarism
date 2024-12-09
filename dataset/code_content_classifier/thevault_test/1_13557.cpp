const IModulePtr ModuleFactory::getModule4Start(const std::string& id)
{
    Locker lock(&m_lock);
    // first of all look at the known modules list
    IModulePtr module = getModuleUnsafe(id);
    if (!module)
    {
        // not found here
        // will try to find at the modules description
        module = getLibFactory()->getModule(id);
        if (module)
        {
            addModule(module);
        }
    }

    if (!module)
    {
        throw Exception(__FILE__, __LINE__,
                        "Unknown module with id: " + id);
    }

    return module;
}