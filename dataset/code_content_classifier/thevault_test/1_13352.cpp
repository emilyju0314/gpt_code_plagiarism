const StringList
SourceAddCommand::getSourceTypeNameList()
{
    StringList list;

    // `klk_app_transcode_source_type_get_cli` (
    // SELECT klk_app_transcode_source_type.type_name AS name FROM
    // klk_app_transcode_source_type;

    db::DB db(getFactory());
    db.connect();
    db::Parameters params;
    db::ResultVector rv = db.callSelect("klk_app_transcode_source_type_get_cli",
                                        params, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}