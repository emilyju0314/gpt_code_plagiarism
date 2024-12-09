void CFTP::ftpCommand(const std::string &command)
    {
        m_lastCommand = command + "\r\n";
        size_t commandLength = m_lastCommand.size();
        do
        {
            commandLength -= m_controlChannelSocket.write(&m_lastCommand[m_lastCommand.size() - commandLength], commandLength);
        } while (commandLength != 0);
        m_lastCommand.pop_back();
        m_lastCommand.pop_back();
        ftpResponse();
    }