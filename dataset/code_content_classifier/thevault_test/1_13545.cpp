void Utils::delStation(const std::string& station)
{
    db::DB db(m_factory);
    db.connect();
    db::Parameters dbparams;
    // IN channel_name VARCHAR(255),
    // OUT return_value INT
    dbparams.add("@channel_name", station);
    dbparams.add("@return_value");
    db::Result dbres = db.callSimple("klk_app_dvb_station_del_cli",
                                        dbparams);

    if (dbres["@return_value"].toInt() != 0)
    {
        throw klk::Exception(__FILE__, __LINE__,
                             "Failed to del station: %s",
                             station.c_str());
    }
}