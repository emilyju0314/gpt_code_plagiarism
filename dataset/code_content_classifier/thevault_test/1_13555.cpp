base::Scheduler* ModuleFactory::getScheduler()
{
    Locker lock(&m_lock);
    try
    {
        if (m_scheduler == NULL)
        {
            m_scheduler = new base::Scheduler();
        }
    }
    catch(const std::bad_alloc&)
    {
        throw klk::Exception(__FILE__, __LINE__, err::MEMORYALLOC);
    }

    return m_scheduler;
}