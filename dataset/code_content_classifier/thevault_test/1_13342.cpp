Factory* Factory::instance()
{
    try
    {
        if (m_instance == NULL)
        {
            m_instance = new Factory();
        }
    }
    catch(const std::bad_alloc&)
    {
        throw Exception(__FILE__, __LINE__, err::MEMORYALLOC);
    }

    return m_instance;
}