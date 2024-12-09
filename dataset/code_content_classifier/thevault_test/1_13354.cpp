const std::string
SourceAddCommand::addSource(const std::string& type,  const std::string& name,
                            const std::string& media_type_name)
{
    db::DB db(getFactory());
    db.connect();

    db::Parameters params;

    // IN source_type_name VARCHAR(255),
    // IN source_name VARCHAR(255),
    // IN media_type_name VARCHAR(255),
    // OUT assigned_source_name VARCHAR(255)
    params.add("@type", type);
    params.add("@name", name);
    params.add("@media_type_name", media_type_name);
    params.add("@assigned");

    db::Result res = db.callSimple("klk_app_transcode_source_add_cli", params);
    if (res["@assigned"].isNull())
    {
        throw Exception(__FILE__, __LINE__, "Failed to add the source");
    }

    return res["@assigned"].toString();

}