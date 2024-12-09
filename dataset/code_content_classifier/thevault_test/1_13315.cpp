void FWSrcInfo::initInternal(Transcode* module)
{
    BOOST_ASSERT(module);

    IFactory* factory = module->getFactory();
    IMessageFactory* msgfactory = factory->getMessageFactory();
    IMessagePtr req = msgfactory->getMessage(msg::id::IEEE1394START);
    BOOST_ASSERT(req);
    req->setData(msg::key::MODINFOUUID, getUUID());
    IMessagePtr res;
    module->sendSyncMessage(req, res);
    BOOST_ASSERT(res);
    if (res->getValue(msg::key::STATUS) != msg::key::OK)
    {
        // net module reject it
        throw Exception(__FILE__, __LINE__,
                        "IEEE1394 module rejected request. Name: %s, UUID: '%s'",
                        getName().c_str(),
                        getUUID().c_str());
    }

    // set the module instance for future cleanup
    m_module = module;

    /*
      port                : Port number (-1 automatic)
                        flags: readable, writable
                        Integer. Range: -1 - 16 Default: -1 Current: -1
     */
    int port = boost::lexical_cast<int>(res->getValue(msg::key::IEEE1394PORT));

    initElement("dv1394src", module->getFactory());
    g_object_set(G_OBJECT (m_element), "port", port, NULL);
}