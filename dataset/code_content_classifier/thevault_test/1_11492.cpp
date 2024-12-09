std::uint16_t CFTP::listDirectory(const std::string &directoryPath, std::string &listOutput)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            listOutput.clear();
            if (sendTransferMode())
            {
                ftpCommand("MLSD " + directoryPath);
                transferOnDataChannel(listOutput);
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }