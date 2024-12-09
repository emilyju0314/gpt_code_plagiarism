const StringList
SourceAddCommand::getMediaTypeList()
{
    StringList list;

    // klk_media_type_list` (
    //SELECT klk_media_types.name AS name FROM klk_media_types;

    db::DB db(getFactory());
    db.connect();

    db::Parameters dbparams;

    db::ResultVector rv = db.callSelect("klk_media_type_list",
                                        dbparams, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}