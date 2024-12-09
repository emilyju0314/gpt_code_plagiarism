const StringList BaseCommand::getSourceNameList()
{
    StringList list;

    db::DB db(getFactory());
    db.connect();

    db::Parameters dbparams;

    db::ResultVector rv = db.callSelect("klk_httpsrc_list",
                                        dbparams, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}