void ModuleFactory::addResources(const std::string& modid,
                                 const IResourcesPtr& res)
{
    BOOST_ASSERT(getResourcesUnsafe(modid) == NULL);
    m_resources.insert(ResourcesMap::value_type(modid, res));
}