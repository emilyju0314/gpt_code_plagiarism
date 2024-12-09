LibFactory* ModuleFactory::getLibFactory()
{
    Locker lock(&m_lock);
    if (m_libfactory == NULL)
    {
        m_libfactory = new LibFactory(m_factory);
    }

    return m_libfactory;
}