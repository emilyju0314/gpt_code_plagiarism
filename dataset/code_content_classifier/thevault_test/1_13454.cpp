const IDevList BaseResources::getResourceByType(const std::string& type) const
{
    IDevList result, devlist = getDevList();
    IsDevNotAtDB notdbcheck;
    if (type == m_type)
    {
        result = devlist;
        // remove devices that don't have UUID and BUSUUID set
        // this means that the devs are not in the DB
        result.remove_if(notdbcheck);
    }
    else
    {
        IsDevHasParam compare;
        for (IDevList::const_iterator i = devlist.begin();
             i != devlist.end(); i++)
        {
            if (compare(*i, dev::TYPE, type) == true &&
                notdbcheck(*i) == false)
            {
                result.push_back(*i);
            }
        }
    }

    // search in subresources
    IResourcesList reslist = getResourcesList();
    for (IResourcesList::const_iterator i = reslist.begin();
         i != reslist.end(); i++)
    {
        const std::string
            type_to_retrive = (type == m_type ? (*i)->getType() : type);
        IDevList add = (*i)->getResourceByType(type_to_retrive);
        result.insert(result.end(), add.begin(), add.end());
    }

    return result;
}