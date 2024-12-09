const StringList
StationAddCommand::getNotAssignedChannels()
{
    StringList list;
    db::DB db(getFactory());
    db.connect();
    db::Parameters dbparams;
    db::ResultVector rv = db.callSelect(
        "klk_app_dvb_station_get_not_assinged_channels",
        dbparams, NULL);

    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["station_name"].toString());
    }
    return list;
}