SNMPFactory* SNMPFactory::instance()
{
    if (m_instance == NULL)
    {
        m_instance = new SNMPFactory();
    }

    return m_instance;
}