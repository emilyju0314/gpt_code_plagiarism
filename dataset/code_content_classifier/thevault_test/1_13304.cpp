const gst::IEventPtr ProcessorThread::getEvent()
{
    gst::IEventPtr event;
    Locker lock(&m_lock);
    if (!m_storage.empty())
    {
        event = m_storage.front();
        m_storage.pop_front();
    }
    return event;
}