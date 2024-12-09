void DVB::updateDB()
{
    // should not be called for a dev with already set UUID
    if (hasParam(UUID))
    {
        // nothing to do
        // we have already had the DB record
        return;
    }

    // getting bus uuid
    const std::string bus_uuid = getBusUUID();
    BOOST_ASSERT(bus_uuid.empty() == false);

    // `klk_dvb_resource_add` (
    // IN bus VARCHAR(40),
    // IN dvb_type VARCHAR(40),
    // IN signal_source VARCHAR(40),
    // IN enabled TINYINT,
    // IN adapter_no TINYINT,
    // IN frontend_no TINYINT,
    // IN resource_name VARCHAR(50),
    // OUT resource VARCHAR(40),
    // OUT return_value INT

    db::Parameters params;
    params.add("@bus", bus_uuid);
    params.add("@dvb_type", getStringParam(TYPE));
    params.add("@signal_source");
    params.add("@enabled", 1); //FIXME!!!
    params.add("@adapter_no", getIntParam(ADAPTER));
    params.add("@frontend_no", getIntParam(FRONTEND));
    params.add("@resource_name", getStringParam(NAME));
    params.add("@resource");
    params.add("@return_value");
    db::DB db(getFactory());
    db.connect();
    db::Result result = db.callSimple(
        "klk_dvb_resource_add",
        params);

    if (result["@return_value"].toInt() != 0)
    {
        throw klk::Exception(__FILE__, __LINE__,
                             "There is a problem with add dev info "
                             "to  DB for a device '" +
                             getStringParam(NAME) + "'");
    }

    BOOST_ASSERT(result["@return_value"].toInt() == 0);
    setParam(UUID, result["@resource"].toString());
    // Free lost lock
    setParam(LOSTLOCK, 0, true);

    klk_log(
        KLKLOG_INFO,
        "Device with name: '%s' type: '%s' uuid: '%s' was added to the DB",
        getStringParam(NAME).c_str(),
        getStringParam(TYPE).c_str(),
        getStringParam(UUID).c_str());
}