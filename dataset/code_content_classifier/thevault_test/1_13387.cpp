IModuleFactory* Factory::getModuleFactory()
{
    Locker lock(&m_lock);
    if (m_module_factory == NULL)
    {
        m_module_factory = new ModuleFactory(this);
    }
    return m_module_factory;
}