std::uint16_t CFTP::getCurrentWoringDirectory(std::string &currentWoringDirectoryPath)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            currentWoringDirectoryPath.clear();
            ftpCommand("PWD");
            if (m_commandStatusCode == 257)
            {
                currentWoringDirectoryPath = m_commandResponse.substr(m_commandResponse.find_first_of('\"') + 1);
                currentWoringDirectoryPath = currentWoringDirectoryPath.substr(0, currentWoringDirectoryPath.find_first_of('\"'));
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }