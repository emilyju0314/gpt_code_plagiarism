const IModulePtr LibFactory::getModule(const std::string& id)
{
    BOOST_ASSERT(id.empty() == false);
    void *handle = NULL;
    handle = getMakeFun(id, "klk_module_get");
    BOOST_ASSERT(handle);

    typedef IModulePtr (*modfactory_func_type) (IFactory*);
    modfactory_func_type fn =
        reinterpret_cast<modfactory_func_type>(handle);
    BOOST_ASSERT(fn);

    IModulePtr res = (*fn)(m_factory);
    BOOST_ASSERT(res);

    return res;
}