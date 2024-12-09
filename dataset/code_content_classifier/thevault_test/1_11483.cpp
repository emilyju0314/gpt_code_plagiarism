void CFTP::ftpResponse()
    {
        m_commandResponse.clear();
        do
        {
            do
            {
                char byte[1];
                if (m_controlChannelSocket.read(&byte[0], 1))
                {
                    m_commandResponse.append(1, byte[0]);
                    if (byte[0] == '\n')
                    {
                        break;
                    }
                }
            } while (!m_controlChannelSocket.closedByRemotePeer());
            if (m_commandResponse[3] == '-')
            {
                if (m_commandResponse.rfind("\r\n" + m_commandResponse.substr(0, 3) + " ") != std::string::npos)
                {
                    break;
                }
            }
        } while ((m_commandResponse[3] == '-') && (!m_controlChannelSocket.closedByRemotePeer()));
        if (m_controlChannelSocket.closedByRemotePeer())
        {
            throw std::runtime_error("Control channel connection closed by peer.");
        }
        try
        {
            m_commandStatusCode = std::stoi(m_commandResponse);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Invalid FTP command response status code.");
        }
    }