void CSocket::connectionListener()
    {
        try
        {
            boost::asio::ip::tcp::acceptor acceptor(m_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));
            m_hostPort = std::to_string(acceptor.local_endpoint().port());
            m_isListenThreadRunning = true;
            std::unique_ptr<SSLSocket> socket = std::make_unique<SSLSocket>(m_ioService, *m_sslContext);
            if (!socket)
            {
                throw std::runtime_error("Could not create socket.");
            }
            acceptor.accept(socket->next_layer(), m_socketError);
            if (m_socketError)
            {
                throw std::runtime_error(m_socketError.message());
            }
            m_socket = std::move(socket);
        }
        catch (const std::exception &e)
        {
            m_thrownException = std::current_exception();
        }
        m_isListenThreadRunning = false;
    }