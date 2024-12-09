void Scan::startScan(const std::string& source, const std::string& data)
{
    // alloc a dev for scan
    IMessageFactory* msgfactory = getFactory()->getMessageFactory();
    BOOST_ASSERT(msgfactory);
    IMessagePtr req = msgfactory->getMessage(msg::id::DVBSTART);
    BOOST_ASSERT(req);
    req->setData(msg::key::DVBACTIVITY, dev::SCANING);
    req->setData(msg::key::DVBSOURCE, source);
    IMessagePtr res;
    sendSyncMessage(req, res);
    // test result
    BOOST_ASSERT(res);

    if (res->getValue(msg::key::STATUS) != msg::key::OK)
    {
        // dvb module rejected the channel
        throw Exception(__FILE__, __LINE__,
                        "DVB module rejected DVB scanning");
    }

    try
    {
        m_thread->startScan(res->getValue(msg::key::RESOURCE), data);
    }
    catch(const std::exception& err)
    {
        klk_log(KLKLOG_ERROR, "There was an error during scan: %s",
                err.what());
        stopScan();
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "There was an unknwon error during scan");
        stopScan();
    }
}