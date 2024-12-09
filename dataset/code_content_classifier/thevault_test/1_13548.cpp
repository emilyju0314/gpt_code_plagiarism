const ISocketPtr UDPListener::accept()
{
    if (m_current)
    {
        m_current->wait();
    }

    if (!m_stop.isStopped())
    {
        if (m_current == NULL)
        {
            int sock = m_sock.getDescriptor();
            m_current = UDPListenSocketPtr(new UDPListenSocket(sock));
        }
        else
        {
            // init for new cicle
            m_current->init();
        }
    }
    else
    {
        m_current.reset();
    }

    return m_current;
}