SMessage MessagesProxy::getMessage(const std::string& id,
                                   const Ice::Current& crn)
{
    IMessagePtr msg = m_factory->getMessageFactory()->getMessage(id);
    return m_converter.msg2ice(msg);
}