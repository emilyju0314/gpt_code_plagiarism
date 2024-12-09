void CIMAP::setServer(const std::string &serverURL)
    {
        m_serverURL = serverURL;
        std::string server = serverURL.substr(serverURL.find("//") + 2);
        m_imapSocket.setHostAddress(server.substr(0, server.find(":")));
        m_imapSocket.setHostPort(serverURL.substr(serverURL.rfind(":") + 1));
    }