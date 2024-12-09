void Network::doList(const IMessagePtr& in, const IMessagePtr& out)
{
    const StringList result = getValues(mod::SELECT_ALL,
                                        mod::NAME);
    out->setData(msg::key::RESULT, result);
}