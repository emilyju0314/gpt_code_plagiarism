const StringList
SourceAddCommand::getSourceNameList(const std::string& type_name)
{
    StringList list;

    // `klk_app_transcode_source_name_missing_get_cli` (
    // SELECT XXX AS name FROM

    db::DB db(getFactory());
    db.connect();
    db::Parameters params;
    params.add("@type_name", type_name);
    db::ResultVector rv =
        db.callSelect("klk_app_transcode_source_name_missing_get_cli", params, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}