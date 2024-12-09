void Network::processDev(const IDevPtr& dev, InfoSet& result)
{
    BOOST_ASSERT(dev);

    db::Parameters params;
    params.add("@resource", dev->getStringParam(dev::UUID));
    db::DB db(getFactory());
    db.connect();
    db::ResultVector rv = db.callSelect("klk_network_route_get",
                                        params, NULL);
    for (db::ResultVector::iterator res = rv.begin();
         res != rv.end(); res++)
    {
        // klk_network_routes.name,
        // klk_network_routes.route,
	// klk_network_routes.host,
	// klk_network_routes.port,
        // klk_network_routes.protocol,
	// klk_network_protocols.proto_name

        const std::string name = (*res)["name"].toString();
        const std::string route = (*res)["route"].toString();
        const std::string host = (*res)["host"].toString();
        const std::string port = (*res)["port"].toString();
        const std::string protocol = (*res)["protocol"].toString();
        const std::string proto_name = (*res)["proto_name"].toString();

        std::string type = msg::key::NETUNICAST;
        if (isMulticast(host))
        {
            type = msg::key::NETMULTICAST;
        }

        RouteInfoPtr info(new RouteInfo(route, name, host,
                                        port, protocol, type, dev,
                                        getFactory()));
        result.insert(info);
        // can be in use by another mediaserver
        // BOOST_ASSERT(info->isInUse(), false);
    }
}