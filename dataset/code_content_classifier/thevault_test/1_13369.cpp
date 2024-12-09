const SourceInfoPtr SourceFactory::getSource(const std::string& uuid,
                                             const std::string& name,
                                             const std::string& media_type,
                                             const std::string& type)

{
    SourceInfoPtr res;

    // look for the element
    // may be it's already exist
    {
        Locker lock(&m_lock);
        SourceInfoContainer::iterator find =
            std::find_if(m_container.begin(), m_container.end(),
                         boost::bind(mod::FindInfoByUUID<SourceInfo>(),
                                     _1, uuid));
        if (find != m_container.end())
            return *find; // found it
    }

    // FIXME!!! bad code
    if (type == type::FILE)
    {
        res = SourceInfoPtr(new FileInfo(uuid, name, media_type));
    }
    else if (type == type::NET)
    {
        res = SourceInfoPtr(new NetInfo(uuid, name, media_type));
    }
    else if (type == type::HTTPSRC)
    {
        res = SourceInfoPtr(new HTTPSrcInfo(uuid, name, media_type));
    }
    else if (type == type::FW)
    {
        res = SourceInfoPtr(new FWSrcInfo(uuid, name, media_type));
    }
    else
    {
        throw Exception(__FILE__, __LINE__, "Unsupported type: " + type);
    }
    return res;
}