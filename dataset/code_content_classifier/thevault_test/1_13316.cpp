void FWSrcInfo::deinit() throw()
{
    try
    {
        if (m_module.getValue())
        {
            IMessageFactory* msgfactory =
                m_module.getValue()->getFactory()->getMessageFactory();
            IMessagePtr req = msgfactory->getMessage(msg::id::IEEE1394STOP);
            BOOST_ASSERT(req);
            req->setData(msg::key::MODINFOUUID, getUUID());
            IMessagePtr res;
            m_module.getValue()->sendSyncMessage(req, res);
            BOOST_ASSERT(res);
            if (res->getValue(msg::key::STATUS) != msg::key::OK)
            {
                // gst module rejected the channel
                throw Exception(__FILE__, __LINE__,
                                "IEEE1394 module rejected request for IEEE1394 stop with name '%s'",
                                getName().c_str());
            }
        }
    }
    catch(...)
    {
        // ignore exception (we should not throw it)
        klk_log(KLKLOG_ERROR, "Error while IEEE1394 info deinitialization");
    }

    m_module = NULL;
    // base cleanup
    SourceInfo::deinit();
}