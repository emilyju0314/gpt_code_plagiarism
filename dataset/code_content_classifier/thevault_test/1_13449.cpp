ServerDaemon* Factory::getServer()
{
    if (m_server == NULL)
    {
        getConfig()->load();
        m_server = new ServerDaemon(this);
    }
    return m_server;
}