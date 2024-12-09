const InThreadPtr Factory::getInThread(const InputInfoPtr& info)
{
    InThreadPtr thread;

    BOOST_ASSERT(info);
    BOOST_ASSERT(info->getRouteInfo()->getHost().empty() == false);

    try
    {
        switch (info->getRouteInfo()->getProtocol())
        {
        case sock::TCPIP:
            thread = InThreadPtr(new InTCPThread(this, info));
            break;
        case sock::UDP:
            thread = InThreadPtr(new InUDPThread(this, info));
            break;
        default:
            throw Exception(__FILE__, __LINE__,
                            "Unsupported net protocol "
                            "for HTTP streamer: %d",
                            info->getRouteInfo()->getProtocol());
        }
    }
    catch(const std::bad_alloc&)
    {
        throw Exception(__FILE__, __LINE__, err::MEMORYALLOC);
    }

    BOOST_ASSERT(thread);

    return thread;
}