const ModuleList ModuleFactory::getModules()
{
    //FIXME!!! move it to lib factory class
    StringList ids = getModuleIDs();
    Locker lock(&m_lock);
    for(StringList::iterator id = ids.begin(); id != ids.end(); id++)
    {
        IModulePtr module = getModuleUnsafe(*id);
        if (!module)
        {
            // not found here
            // will try to find at the modules description
            module = getLibFactory()->getModule(*id);
            BOOST_ASSERT(module);
            if (module)
            {
                addModule(module);
            }
        }

    }
    return m_modules;
}