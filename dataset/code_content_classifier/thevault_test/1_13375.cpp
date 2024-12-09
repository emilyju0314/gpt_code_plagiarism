void ModuleFactory::addDebug(const IModulePtr& module)
{
    klk::Locker lock(&m_lock);
    addModule(module);
}