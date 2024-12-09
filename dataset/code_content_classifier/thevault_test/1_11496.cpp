std::uint16_t CFTP::getModifiedDateTime(const std::string &filePath, DateTime &modifiedDateTime)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            ftpCommand("MDTM " + filePath);
            if (m_commandStatusCode == 213)
            {
                std::string dateTime = m_commandResponse.substr(m_commandResponse.find(' ') + 1);
                modifiedDateTime.year = std::stoi(dateTime.substr(0, 4));
                modifiedDateTime.month = std::stoi(dateTime.substr(4, 2));
                modifiedDateTime.day = std::stoi(dateTime.substr(6, 2));
                modifiedDateTime.hour = std::stoi(dateTime.substr(8, 2));
                modifiedDateTime.minute = std::stoi(dateTime.substr(10, 2));
                modifiedDateTime.second = std::stoi(dateTime.substr(12, 2));
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }