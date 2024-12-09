std::string CFTP::createPortCommand()
    {
        std::string portCommand{"PORT "};
        try
        {
            std::uint16_t port = std::stoi(m_dataChannelSocket.getHostPort());
            portCommand += m_dataChannelSocket.getHostAddress();
            for (auto &byte : portCommand)
            {
                if (byte == '.')
                    byte = ',';
            }
            portCommand += "," + std::to_string((port & 0xFF00) >> 8) + "," + std::to_string(port & 0xFF);
        }
        catch (const std::exception &e)
        {
            throw;
        }
        return (portCommand);
    }