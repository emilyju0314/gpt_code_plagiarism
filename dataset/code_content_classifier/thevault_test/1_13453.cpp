const IDevPtr BaseResources::getResourceByUUID(const std::string& uuid)
    const
{
    // FIXME!!! can be slow -change the algorithm
    // get everything
    IDevList list = getResourceByType(m_type);
    // serch in the result
    IDevList::iterator i = std::find_if(
        list.begin(), list.end(),
        boost::bind<bool>(IsDevHasParam(), _1, dev::UUID, uuid));

    if (i == list.end())
    {
        throw Exception(__FILE__, __LINE__,
                             "Cannot find dev with UUID: " + uuid);
    }

    return *i;
}