void BaseResources::removeMissing(const std::string& bus_uuid,
                                  const std::string& type)
{
    // IN bus VARCHAR(40)
    db::Parameters params;
    db::DB db(m_factory);
    db.connect();
    params.add("@bus", bus_uuid);
    db::ResultVector rv = db.callSelect("klk_resource_list",
                                           params, NULL);
    for (db::ResultVector::iterator i = rv.begin(); i != rv.end(); i++)
    {
        //SELECT
        //klk_resources.resource,
        //klk_resources.resource_type,
        //klk_resources.bandwidth,
        //klk_resources.enabled,
        //klk_resources.resource_name

        if (type != (*i)["resource_type"].toString())
            continue; // nothing to do
        const std::string uuid = (*i)["resource"].toString();
        try
        {
            getResourceByUUID(uuid);
        }
        catch(...)
        {
            // delete the resource
            // `klk_resource_delete` (
            // IN resource VARCHAR(40),
            // OUT return_value INTEGER
            params.clear();
            params.add("@resource", uuid);
            params.add("@return_value");
            db::Result result = db.callSimple("klk_resource_delete",
                                                 params);
            if (result["@return_value"].toInt() != 0)
            {
                klk_log(KLKLOG_ERROR,
                        "Failed to delete a resource with uuid '%s' "
                        "from the DB", uuid.c_str());
            }
        }
    }
}