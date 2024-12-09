void CFTP::transferOnDataChannel(const std::string &file, DataTransferType transferType)
    {
        std::string unusedResponse;
        transferOnDataChannel(file, unusedResponse, transferType);
    }