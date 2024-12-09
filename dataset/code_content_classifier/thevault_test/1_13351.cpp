const StringList
StationDelCommand::getAssignedChannels()
{
    StringList list;
    db::DB db(getFactory());
    db.connect();
    db::Parameters dbparams;
    db::ResultVector rv = db.callSelect(
        "klk_app_dvb_station_list",
        dbparams, NULL);

    // determine max sizes
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        //klk_dvb_channels.name . '/' . klk_dvb_channels.provider AS
        //   station_name,
        // ...
        list.push_back((*item)["station_name"].toString());
    }
    return list;
}