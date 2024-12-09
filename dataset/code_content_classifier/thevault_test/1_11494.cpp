std::uint16_t CFTP::changeWorkingDirectory(const std::string &workingDirectoryPath)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            ftpCommand("CWD " + workingDirectoryPath);
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }