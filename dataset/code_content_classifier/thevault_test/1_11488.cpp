std::uint16_t CFTP::getFile(const std::string &remoteFilePath, const std::string &localFilePath)
    {
        try
        {
            std::ofstream localFile{localFilePath, std::ofstream::binary};
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            if (localFile)
            {
                localFile.close();
                if (sendTransferMode())
                {
                    ftpCommand("RETR " + remoteFilePath);
                    transferOnDataChannel(localFilePath, DataTransferType::download);
                }
            }
            else
            {
                m_commandStatusCode = 550;
                throw std::runtime_error("Local file " + localFilePath + " could not be created.");
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }