void Thread::freeBus()
{
    Locker lock(&m_bus_lock);
    // stop processing events
    if (m_bus_id)
    {
        if (!g_source_remove(m_bus_id))
        {
            klk_log(KLKLOG_ERROR, "Cannot remove watch source with id: %lu", m_bus_id);
        }
        m_bus_id = 0;
    }
}