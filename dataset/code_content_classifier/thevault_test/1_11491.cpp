std::uint16_t CFTP::listFiles(const std::string &directoryPath, FileList &fileList)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            fileList.clear();
            if (sendTransferMode())
            {
                std::string listOutput;
                ftpCommand("NLST " + directoryPath);
                transferOnDataChannel(listOutput);
                if (m_commandStatusCode == 226)
                {
                    std::string file;
                    std::istringstream listOutputStream{listOutput};
                    while (std::getline(listOutputStream, file, '\n'))
                    {
                        file.pop_back();
                        fileList.push_back(file);
                    }
                }
            }
            return (m_commandStatusCode);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }