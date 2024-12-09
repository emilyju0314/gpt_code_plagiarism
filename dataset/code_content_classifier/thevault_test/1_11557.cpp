std::string CIMAP::sendCommand(const std::string &commandLine)
    {
        try
        {
            if (!m_connected)
            {
                throw Exception("Not connected to server.");
            }
            generateTag();
            if (commandLine.compare(kIDLE) == 0)
            {
                sendCommandIDLE(m_currentTag + " " + commandLine + kEOL);
            }
            else if (commandLine.compare(kAPPEND) == 0)
            {
                sendCommandAPPEND(m_currentTag + " " + commandLine);
            }
            else
            {
                sendIMAPCommand(m_currentTag + " " + commandLine + kEOL);
                waitForIMAPCommandResponse(m_currentTag, m_commandResponse);
            }
            // If response is empty then server disconnect without BYE
            if (m_commandResponse.empty())
            {
                disconnect();
                throw std::runtime_error("Server Disconnect without BYE.");
            }
            return (m_currentTag + " " + commandLine + kEOL + m_commandResponse);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }