void Station::setFailed() throw()
{
    try
    {
        // `klk_app_dvb_failed_station_add` (
        //IN station_uuid VARCHAR(40),
        //IN host_uuid VARCHAR(40)
        db::DB db(m_factory);
        db.connect();
        db::Parameters params;
        params.add("@station", getUUID());
        params.add("@host", db.getHostUUID());
        db.callSimple("klk_app_dvb_failed_station_add", params);
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "Exception in Station::setFailed()");
    }
}