bool CFTP::isDirectory(const std::string &fileName)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            // Try MLST first then STAT
            ftpCommand("MLST " + fileName);
            if (m_commandStatusCode == 250)
            {
                size_t dirPosition = m_commandResponse.find("Type=dir;");
                if (dirPosition != std::string::npos)
                {
                    return (true);
                }
            }
            else if (m_commandStatusCode == 500)
            {
                ftpCommand("STAT " + fileName);
                if ((m_commandStatusCode == 213) || (m_commandStatusCode == 212))
                {
                    size_t dirPosition = m_commandResponse.find("\r\n") + 2;
                    if ((dirPosition != std::string::npos) &&
                        (m_commandResponse[dirPosition] == 'd'))
                    {
                        return (true);
                    }
                }
            }
            return (false);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }