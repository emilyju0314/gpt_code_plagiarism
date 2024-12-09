std::vector<std::string> CFTP::getServerFeatures()
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            if (m_serverFeatures.empty())
            {
                ftpServerFeatures();
            }
            return (m_serverFeatures);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }