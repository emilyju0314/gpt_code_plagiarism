void TestHelpModule::testInvalid()
{
    IMessageFactory* msgfactory = getFactory()->getMessageFactory();
    BOOST_ASSERT(msgfactory);
    IMessagePtr request = msgfactory->getMessage(msg::id::HTTPSRCSTART);
    BOOST_ASSERT(request);
    request->setData(msg::key::MODINFOUUID, "invalid_id");
    IMessagePtr response;
    sendSyncMessage(request, response);
    BOOST_ASSERT(response);
    BOOST_ASSERT(response->getValue(msg::key::STATUS) == msg::key::FAILED);
}