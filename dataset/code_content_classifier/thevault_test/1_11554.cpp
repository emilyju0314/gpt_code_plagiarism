void CIMAP::sendCommandIDLE(const std::string &commandLine)
    {
        std::string response;
        sendIMAPCommand(commandLine);
        waitForIMAPCommandResponse(kContinuation, m_commandResponse);
        if (!m_commandResponse.empty())
        {
            waitForIMAPCommandResponse(kUntagged, response);
            if (!response.empty())
            {
                sendIMAPCommand(static_cast<std::string>(kDONE) + kEOL);
                waitForIMAPCommandResponse(m_currentTag, m_commandResponse);
                if (!m_commandResponse.empty())
                {
                    response += m_commandResponse;
                    m_commandResponse = response;
                }
            }
            else
            {
                m_commandResponse.clear();
            }
        }
    }