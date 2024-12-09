void Stream::updateRate(IStationPtr& station) throw()
{
    if (!station)
        return; // nothing to do

    u_int pnr = station->getChannelNumber();

    try
    {
        struct stream_s* stream = getStreamStruct(pnr);
        BOOST_ASSERT(stream);

        int rate = getRate(stream->klkstat);
        station->setRate(rate);
    }
    catch(const std::exception& err)
    {
        klk_log(KLKLOG_ERROR, "Failed to update rate for channel '%d': %s",
                pnr,
                err.what());
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "Failed to update rate for channel '%d': "
                "unknown error", pnr);
    }
}