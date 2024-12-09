void CFTP::downloadFile(const std::string &file)
    {
        std::ofstream localFile{file, std::ofstream::trunc | std::ofstream::binary};
        do
        {
            size_t bytesRead = m_dataChannelSocket.read(m_ioBuffer.get(), m_ioBufferSize);
            if (bytesRead)
            {
                localFile.write(m_ioBuffer.get(), bytesRead);
            }
        } while (!m_dataChannelSocket.closedByRemotePeer());
        localFile.close();
    }