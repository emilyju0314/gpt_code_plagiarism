const bool Stream::isStream() const
{
    Locker lock(&m_lock);
    return !m_streams.empty();
}