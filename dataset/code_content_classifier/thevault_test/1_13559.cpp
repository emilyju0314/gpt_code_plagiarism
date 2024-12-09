IResourcesPtr ModuleFactory::getResourcesUnsafe(const std::string& id)
{
    BOOST_ASSERT(id.empty() == false);

    IResourcesPtr res;
    ResourcesMap::iterator i = m_resources.find(id);
    if (i != m_resources.end())
    {
        res = i->second;
    }

    return res;
}