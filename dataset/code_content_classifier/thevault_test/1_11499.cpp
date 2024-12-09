void CFTP::setBinaryTransfer(bool binaryTransfer)
    {
        try
        {
            if (!m_connected)
            {
                throw std::logic_error("Already connected to a server.");
            }
            if (binaryTransfer)
            {
                ftpCommand("TYPE I");
            }
            else
            {
                ftpCommand("TYPE A");
            }
            if (m_commandStatusCode == 200)
            {
                m_binaryTransfer = binaryTransfer;
            }
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }