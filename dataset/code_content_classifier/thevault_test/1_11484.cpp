bool CFTP::sendTransferMode()
    {
        if (m_passiveMode)
        {
            ftpCommand("PASV");
            if (m_commandStatusCode == 227)
            {
                extractPassiveAddressPort(m_commandResponse);
                m_dataChannelSocket.connect();
            }
            return (m_commandStatusCode == 227);
        }
        else
        {
            m_dataChannelSocket.setHostAddress(Antik::Network::CSocket::localIPAddress());
            m_dataChannelSocket.listenForConnection();
            ftpCommand(createPortCommand());
            return (m_commandStatusCode == 200);
        }
    }