void CSocket::close()
    {
        try
        {
            std::unique_ptr<SSLSocket> socket{std::move(m_socket)};
            // Socket exists and is open
            if (socket && socket->next_layer().is_open())
            {
                // Shutdown TLS
                if (m_sslActive)
                {
                    m_sslActive = false;
                    socket->shutdown(m_socketError);
                }
                // Close socket
                socket->next_layer().close(m_socketError);
                if (m_socketError)
                {
                    throw std::runtime_error(m_socketError.message());
                }
            }
            // Remove any listen thread
            if (m_socketListenThread)
            {
                m_socketListenThread.reset();
            }
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }