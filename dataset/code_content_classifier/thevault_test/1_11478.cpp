void CFTP::downloadCommandResponse(std::string &commandResponse)
    {
        do
        {
            size_t bytesRead = m_dataChannelSocket.read(m_ioBuffer.get(), m_ioBufferSize - 1);
            if (bytesRead)
            {
                m_ioBuffer.get()[bytesRead] = '\0';
                commandResponse.append(m_ioBuffer.get());
            }
        } while (!m_dataChannelSocket.closedByRemotePeer());
    }