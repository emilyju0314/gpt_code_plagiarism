bool Station::isInUse() throw()
{
    bool res = false;

    try
    {
        // `klk_app_dvb_station_getlock` (
        // IN station VARCHAR(40),
        // OUT return_value INT

        db::Parameters params;
        params.add("@station", getUUID());
        params.add("@return_value");
        db::DB db(m_factory);
        db.connect();
        db::Result db_result = db.callSimple(
            "klk_app_dvb_station_getlock",
            params);

        res = (db_result["@return_value"].toInt() == 1);
    }
    catch (...)
    {
        klk_log(KLKLOG_ERROR, "Got an error while determine "
                "dvb-streamer station in use info");
        return false; // not in use
    }

    return res;
}