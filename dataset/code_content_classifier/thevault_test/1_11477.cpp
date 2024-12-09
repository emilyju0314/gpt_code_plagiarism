void CFTP::uploadFile(const std::string &file)
    {
        std::ifstream localFile{file, std::ifstream::binary};
        if (localFile)
        {
            do
            {
                localFile.read(m_ioBuffer.get(), m_ioBufferSize);
                size_t bytesToWrite = localFile.gcount();
                if (bytesToWrite)
                {
                    for (;;)
                    {
                        bytesToWrite -= m_dataChannelSocket.write(&m_ioBuffer.get()[localFile.gcount() - bytesToWrite], bytesToWrite);
                        if ((bytesToWrite == 0) || m_dataChannelSocket.closedByRemotePeer())
                        {
                            break;
                        }
                    }
                }
            } while (localFile && !m_dataChannelSocket.closedByRemotePeer());
            localFile.close();
        }
    }