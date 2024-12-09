const RouteInfoPtr Streamer::getRouteInfoByUUID(const std::string& uuid)
{
    BOOST_ASSERT(uuid.empty() == false);

    IMessageFactory* msgfactory = getFactory()->getMessageFactory();
    IMessagePtr req = msgfactory->getMessage(msg::id::NETINFO);
    BOOST_ASSERT(req);
    req->setData(msg::key::MODINFOUUID, uuid);
    IMessagePtr res;
    sendSyncMessage(req, res);
    BOOST_ASSERT(res);
    if (res->getValue(msg::key::STATUS) != msg::key::OK)
    {
        // gst module rejected the channel
        throw Exception(__FILE__, __LINE__,
                        "Net module rejected route '%s'",
                        uuid.c_str());
    }
    const std::string name = res->getValue(msg::key::MODINFONAME);
    const std::string host = res->getValue(msg::key::NETHOST);

    sock::Type type = sock::UNICAST;
    if (res->getValue(msg::key::NETTYPE) == msg::key::NETMULTICAST)
    {
        type = sock::MULTICAST;
    }

    u_int port = 0;
    try
    {
        port = boost::lexical_cast<u_int>(res->getValue(msg::key::NETPORT));
    }
    catch(const boost::bad_lexical_cast&)
    {
        throw Exception(__FILE__, __LINE__, err::BADLEXCAST);
    }

    sock::Protocol proto = sock::TCPIP;
    if (res->getValue(msg::key::NETPROTO) == net::UDP)
    {
        proto = sock::UDP;
    }
    else
    {
        // FIXME!!! place it at separate method
        // we should lock it (TCP input should be unique - it's a server)
        IMessagePtr req_start = msgfactory->getMessage(msg::id::NETSTART);
        BOOST_ASSERT(req_start);
        req_start->setData(msg::key::MODINFOUUID, uuid);
        IMessagePtr res_start;
        sendSyncMessage(req_start, res_start);
        BOOST_ASSERT(res_start);
        if (res_start->getValue(msg::key::STATUS) != msg::key::OK)
        {
            // gst module rejected the channel
            throw Exception(__FILE__, __LINE__,
                            "Net module rejected route '%s'",
                            uuid.c_str());
        }
    }

    return RouteInfoPtr(new RouteInfo(uuid, name, host, port, proto, type));
}