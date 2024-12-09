void ModuleFactory::addModule(const IModulePtr& module)
{
    BOOST_ASSERT(module);
    std::string modid = module->getID();
    BOOST_ASSERT(getModuleUnsafe(modid) == NULL);
    // register messages
    module->registerProcessors();
    m_modules.push_back(module);
}