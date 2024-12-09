void CFTP::extractPassiveAddressPort(std::string &pasvResponse)
    {
        try
        {
            std::string passiveParams = pasvResponse.substr(pasvResponse.find('(') + 1);
            passiveParams = passiveParams.substr(0, passiveParams.find(')'));
            std::uint32_t port = std::stoi(passiveParams.substr(passiveParams.find_last_of(',') + 1));
            passiveParams = passiveParams.substr(0, passiveParams.find_last_of(','));
            port |= (std::stoi(passiveParams.substr(passiveParams.find_last_of(',') + 1)) << 8);
            passiveParams = passiveParams.substr(0, passiveParams.find_last_of(','));
            for (auto &byte : passiveParams)
            {
                if (byte == ',')
                    byte = '.';
            }
            m_dataChannelSocket.setHostAddress(passiveParams);
            m_dataChannelSocket.setHostPort(std::to_string(port));
        }
        catch (const std::exception &e)
        {
            throw;
        }
    }