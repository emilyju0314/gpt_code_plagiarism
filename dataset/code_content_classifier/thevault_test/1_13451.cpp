bool BaseResources::hasDev(const std::string& type) const
{
    if (type == m_type)
    {
        // whole list indicates that type match
        return true;
    }

    IDevList devlist = getDevList();

    IDevList::const_iterator i = std::find_if(
        devlist.begin(), devlist.end(),
        boost::bind<bool>(IsDevHasParam(), _1, dev::TYPE, type));

    if (i != devlist.end())
        return true; // found in dev list

    boost::function1<bool, IResourcesPtr>
        compare = boost::bind(&IResources::hasDev, _1, type);
    // not found, try sub resources
    IResourcesList reslist = getResourcesList();
    IResourcesList::const_iterator j = std::find_if(
        reslist.begin(), reslist.end(),
        boost::bind<bool>(compare, _1));
    if (j != reslist.end())
        return true; // found in sub resources

    return false;
}