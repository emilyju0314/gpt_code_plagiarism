void Message::addReceiver(const std::string& id)
{
    Locker lock(&m_lock);
    // check that it does not exist
    StringList::iterator i =
        std::find(m_receivers.begin(), m_receivers.end(), id);
    BOOST_ASSERT(i == m_receivers.end());
    m_receivers.push_back(id);
}