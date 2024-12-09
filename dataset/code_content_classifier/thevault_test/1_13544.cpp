void Utils::addStation(const std::string& station, const std::string& route,
                       const char* priority)
{
    db::DB db(m_factory);
    db.connect();
    db::Parameters params;
    // IN channel_name VARCHAR(255),
    // IN route_name VARCHAR(255),
    // IN priority INTEGER,
    // OUT return_value INT
    params.add("@station_name", station);
    params.add("@route_name", route);
    if (priority)
    {
        params.add("@priority", priority);
    }
    else
    {
        params.add("@priority");
    }

    params.add("@return_value");
    db::Result dbres = db.callSimple("klk_app_dvb_station_add_cli",
                                        params);
    if (dbres["@return_value"].toInt() != 0)
    {
        throw klk::Exception(__FILE__, __LINE__,
                             "Failed to add station: %s -> %s",
                             station.c_str(), route.c_str());
    }
}