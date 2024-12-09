std::string LibFactory::getPath(const std::string& id) const
{
    std::string res;
    std::string folder = dir::SHARE + "/modules";
    StringList list = base::Utils::getFiles(folder);
    for (StringList::iterator i = list.begin(); i != list.end(); i++)
    {
        res = getPathFromDescription(id, *i);
        if (!res.empty())
            break;
    }
    if (res.empty())
    {
        throw Exception(__FILE__, __LINE__,
                             "Cannot get library path for module with id: " +
                             id);
    }
    return res;
}