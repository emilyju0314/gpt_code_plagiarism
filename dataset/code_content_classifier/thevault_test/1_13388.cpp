IMessageFactory* Factory::getMessageFactory()
{
    Locker lock(&m_lock);
    if (m_message_factory == NULL)
    {
        m_message_factory = new MessageFactory(this);
    }
    return m_message_factory;
}