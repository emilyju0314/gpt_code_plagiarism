const StringList Adapter::getReceiverList(const IMessagePtr& in)
{
    klk::Locker lock(&m_remote_mutex);
    return m_remote_messages[in->getID()];
}