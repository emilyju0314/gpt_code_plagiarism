void CSocket::connect()
    {
        try
        {
            std::unique_ptr<SSLSocket> socket = std::make_unique<SSLSocket>(m_ioService, *m_sslContext);
            if (!socket)
            {
                throw std::runtime_error("Could not create socket.");
            }
            boost::asio::ip::tcp::resolver::query query{m_hostAddress, m_hostPort};
            socket->next_layer().connect(*m_ioQueryResolver.resolve(query), m_socketError);
            if (m_socketError)
            {
                throw std::runtime_error(m_socketError.message());
            }
            m_socket = std::move(socket);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }