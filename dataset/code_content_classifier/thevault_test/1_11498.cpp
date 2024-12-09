bool CFTP::fileExists(const std::string &fileName)
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
                return (true);
            }
            else if (m_commandStatusCode == 500)
            {
                ftpCommand("STAT " + fileName);
                // If 212/213 returned check the response is not empty; if it is
                // file does not exist.
                if ((m_commandStatusCode == 213) || (m_commandStatusCode == 212))
                {
                    size_t statusCodePosition = m_commandResponse.find("\r\n") + 2;
                    if ((statusCodePosition != std::string::npos) &&
                        (m_commandResponse[statusCodePosition] != '2'))
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