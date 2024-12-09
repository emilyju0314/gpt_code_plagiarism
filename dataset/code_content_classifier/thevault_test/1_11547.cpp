size_t CSocket::read(char *readBuffer, size_t bufferLength)
    {
        try
        {
            size_t bytesRead{0};
            // No socket present
            if (!m_socket)
            {
                throw std::logic_error("No socket present.");
            }
            // Read data
            if (m_sslActive)
            {
                bytesRead = m_socket->read_some(boost::asio::buffer(readBuffer, bufferLength), m_socketError);
            }
            else
            {
                bytesRead = m_socket->next_layer().read_some(boost::asio::buffer(readBuffer, bufferLength), m_socketError);
            }
            // Signal any non end of file  error
            if (m_socketError && m_socketError != boost::asio::error::eof)
            {
                throw std::runtime_error(m_socketError.message());
            }
            return (bytesRead);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }