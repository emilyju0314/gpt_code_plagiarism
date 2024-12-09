void Net::update()
{
    // getting bus uuid
    const std::string bus_uuid = getBusUUID();
    BOOST_ASSERT(bus_uuid.empty() == false);

    // IN bus VARCHAR(40)
    // SELECT
    // klk_resources.resource_name,
    // klk_resources.bus,
    // klk_resources.resource,
    // klk_resources.bandwidth,
    // klk_network_interface_addresses.ip_address,
    // klk_network_interface_addresses.ip_mask
    // klk_network_interface_addresses.address
    db::DB db(getFactory());
    db.connect();

    db::Parameters params;
    params.add("@host_uuid", db.getHostUUID());

    db::ResultVector
        rv = db.callSelect("klk_network_resources_list", params, NULL);

    for (db::ResultVector::iterator res = rv.begin();
         res != rv.end(); res++)
    {
        // looking for the name
        if (getStringParam(NAME) == (*res)["resource_name"].toString())
        {
            setParam(UUID, (*res)["resource"].toString());
            setParam(NETADDRUUID, (*res)["address"].toString());
            setParam(BUSUUID, bus_uuid);
            if ((*res)["bandwidth"].isNull())
            {
                // FIXME!!!
                setParam(BANDWIDTH, 0);
            }
            else
            {
                setParam(BANDWIDTH, (*res)["bandwidth"].toInt());
            }


            klk_log(
                KLKLOG_INFO,
                "Registered network device name: '%s' type: '%s' uuid: '%s'",
                getStringParam(NAME).c_str(),
                getStringParam(TYPE).c_str(),
                getStringParam(UUID).c_str());
            break;
        }
    }
}