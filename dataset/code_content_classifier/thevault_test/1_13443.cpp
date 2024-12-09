void Adapter::updateDB4ObjectAdapter(const std::string& object_id,
                                     const std::string& connection_string)
{
    // `klk_adapter_update` (
    // IN host_uuid VARCHAR(40),
    // IN module_id VARCHAR(40),
    // IN object_id VARCHAR(40),
    // IN endpoint VARCHAR(255),
    // OUT return_value INT
    // retrive route information
    db::DB db(getFactory());
    db.connect();

    db::Parameters params;
    params.add("@host", db.getHostUUID());
    params.add("@module", getFactory()->getMainModuleId());
    params.add("@object", object_id);
    if (connection_string.empty())
    {
        params.add("@endpoint");
    }
    else
    {
        params.add("@endpoint", connection_string);
    }
    params.add("@return_value");

    db::Result res = db.callSimple("klk_adapter_update", params);
    if (res["@return_value"].toInt() != 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "DB error while adapter setting update");
    }

}