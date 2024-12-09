void CFTP::transferOnDataChannel(std::string &commandRespnse)
    {
        std::string unusedFile;
        transferOnDataChannel(unusedFile, commandRespnse, DataTransferType::commandResponse);
    }