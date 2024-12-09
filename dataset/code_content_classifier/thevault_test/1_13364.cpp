const StringList
StationAddCommand::getNotAssignedRoutes()
{
    // FIXME!!! need refactoring
    // (same realization as getNotAssignedChannels)
    StringList list;
    db::DB db(getFactory());
    db.connect();
    db::Parameters dbparams;
    db::ResultVector rv = db.callSelect(
        "klk_app_dvb_station_get_not_assinged_routes",
        dbparams, NULL);

    // determine max sizes
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }
    return list;
}