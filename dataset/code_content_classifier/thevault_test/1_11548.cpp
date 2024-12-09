void CSocket::tlsHandshake()
    {
        try
        {
            // If SSL not enabled return
            if (!m_sslEnabled)
            {
                return;
            }
            // No socket present
            if (!m_socket)
            {
                throw std::logic_error("No socket present.");
            }
            m_socket->handshake(SSLSocket::client, m_socketError);
            if (m_socketError)
            {
                throw std::runtime_error(m_socketError.message());
            }
            m_sslActive = true;
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }