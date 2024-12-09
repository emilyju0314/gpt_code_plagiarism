std::uint16_t CFTP::listFile(const std::string &filePath, std::string &listOutput)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            listOutput.clear();
            ftpCommand("MLST " + filePath);
            if (m_commandStatusCode == 250)
            {
                listOutput = m_commandResponse.substr(m_commandResponse.find('\n') + 1);
                listOutput = listOutput.substr(0, listOutput.find('\r'));
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }