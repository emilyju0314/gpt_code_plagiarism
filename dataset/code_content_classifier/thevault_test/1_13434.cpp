IMessagePtr MessageFactory::getResponse(const IMessagePtr& request) const

{
    BOOST_ASSERT(request);
    BOOST_ASSERT(request->getType() == msg::SYNC_REQ);
    IMessagePtr response(new Message(request->getID(),
                                     request->getUUID()));
    response->setType(msg::SYNC_RES);
    return response;
}