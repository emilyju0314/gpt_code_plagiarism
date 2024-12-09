void CIMAP::sendCommandAPPEND(const std::string &commandLine)
    {
        sendIMAPCommand(commandLine.substr(0, commandLine.find_first_of('}') + 1) + kEOL);
        waitForIMAPCommandResponse(kContinuation, m_commandResponse);
        if (!m_commandResponse.empty())
        {
            sendIMAPCommand(commandLine.substr(commandLine.find_first_of('}') + 1));
            waitForIMAPCommandResponse(m_currentTag, m_commandResponse);
        }
    }