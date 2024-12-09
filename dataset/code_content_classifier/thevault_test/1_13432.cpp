void Station::updateInUse() throw()
{
    // some of info can be missing at the db
    // thus we catch all exceptions here
    try
    {
        db::DB db(m_factory);
        db.connect();

        db::Parameters params;
        params.add("@station", getUUID());
        params.add("@used_host", db.getHostUUID());
        params.add("@return_value");

        db::Result result = db.callSimple("klk_app_dvb_station_update_lock",
                                          params);
        BOOST_ASSERT(result["@return_value"].toInt() == 0);
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "Failed to update DVB streamer usage "
                "info for '%s'", getName().c_str());
    }
}