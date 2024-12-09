const StringList
BaseCommand::getTaskNameList()
{
    StringList list;

    db::DB db(getFactory());
    db.connect();

    db::Parameters dbparams;

    db::ResultVector rv = db.callSelect("klk_app_transcode_get",
                                        dbparams, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["task_name"].toString());
    }

    return list;
}