const klk::IResourcesPtr ModuleFactory::getResources(const std::string& id)
{
    if (id.find(klk::test::HELPPREFIX) != std::string::npos)
    {
        // return empty
        // don't search for help modules
        return klk::IResourcesPtr();
    }

    return klk::ModuleFactory::getResources(id);
}