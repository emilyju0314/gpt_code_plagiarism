std::uint16_t CFTP::putFile(const std::string &remoteFilePath, const std::string &localFilePath)
    {
        try
        {
            std::ifstream localFile{localFilePath, std::ifstream::binary};
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            if (localFile)
            {
                localFile.close();
                if (sendTransferMode())
                {
                    ftpCommand("STOR " + remoteFilePath);
                    transferOnDataChannel(localFilePath, DataTransferType::upload);
                }
            }
            else
            {
                m_commandStatusCode = 550;
                throw std::runtime_error("Local file " + localFilePath + " does not exist.");
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }