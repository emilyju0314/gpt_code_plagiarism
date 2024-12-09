const StringList Message::getReceiverList() const throw()
{
    Locker lock(&m_lock);
    return m_receivers;
}