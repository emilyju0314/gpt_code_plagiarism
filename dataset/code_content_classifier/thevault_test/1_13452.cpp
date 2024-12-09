const IDevPtr BaseResources::getResourceByName(const std::string& name)
    const
{
    // FIXME!!! can be slow -change the algorithm
    // get everything
    IDevList list = getResourceByType(m_type);
    // search in the list
    IDevList::iterator i = std::find_if(
        list.begin(), list.end(),
        boost::bind<bool>(IsDevHasParam(), _1, dev::NAME, name));

    if (i == list.end())
    {
        throw Exception(__FILE__, __LINE__,
                             "Cannot find dev with name: " + name);
    }

    return *i;
}