void CSocket::setTLSVersion(TLSVerion version)
    {
        m_tlsVersion = version;
        switch (m_tlsVersion)
        {
        case TLSVerion::v1_0:
            m_sslContext = std::make_unique<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);
            break;
        case TLSVerion::v1_1:
            m_sslContext = std::make_unique<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv11);
            break;
        case TLSVerion::v1_2:
            m_sslContext = std::make_unique<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12);
            break;
        }
    }