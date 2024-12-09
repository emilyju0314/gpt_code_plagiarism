void CSocket::cleanup()
    {
        try
        {
            if (m_isListenThreadRunning && m_socketListenThread)
            {
                m_isListenThreadRunning = false;
                try
                {
                    boost::asio::ip::tcp::socket socket{m_ioService};
                    boost::asio::ip::tcp::resolver::query query(m_hostAddress, m_hostPort);
                    boost::asio::connect(socket, m_ioQueryResolver.resolve(query));
                    socket.close();
                }
                catch (std::exception &e)
                {
                    throw std::runtime_error("Could not wake listener thread with fake connect.");
                }
                m_socketListenThread->join();
            }
            close();
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }