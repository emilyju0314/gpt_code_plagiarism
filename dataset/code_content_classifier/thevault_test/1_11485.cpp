void CFTP::ftpServerFeatures(void)
    {
        ftpCommand("FEAT");
        if (m_commandStatusCode == 211)
        {
            std::string feature;
            std::istringstream featureResponseStream{m_commandResponse};
            std::getline(featureResponseStream, feature, '\n');
            m_serverFeatures.clear();
            while (std::getline(featureResponseStream, feature, '\n'))
            {
                feature.pop_back();
                m_serverFeatures.push_back(feature.substr(1));
            }
            m_serverFeatures.pop_back();
        }
    }