void CSocket::waitUntilConnected()
    {
        try
        {
            // Listener thread is running (wait for it to finish)
            if (m_socketListenThread)
            {
                m_socketListenThread->join();
            }
            // TLS handshake if SSL enabled
            tlsHandshake();
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }