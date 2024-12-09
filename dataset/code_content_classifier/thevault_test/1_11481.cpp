void CFTP::transferOnDataChannel(const std::string &file, std::string &commandRespnse, DataTransferType transferType)
    {
        try
        {
            if ((m_commandStatusCode == 125) || (m_commandStatusCode == 150))
            {
                m_dataChannelSocket.waitUntilConnected();
                switch (transferType)
                {
                case DataTransferType::download:
                    downloadFile(file);
                    break;
                case DataTransferType::upload:
                    uploadFile(file);
                    break;
                case DataTransferType::commandResponse:
                    downloadCommandResponse(commandRespnse);
                    break;
                }
                m_dataChannelSocket.close();
                ftpResponse();
            }
        }
        catch (const std::exception &e)
        {
            m_dataChannelSocket.cleanup();
            throw;
        }
        m_dataChannelSocket.cleanup();
    }