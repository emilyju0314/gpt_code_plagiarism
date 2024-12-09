std::vector<int16_t>
    SoundBufferIO::readNextBuffer()
    {
        std::ifstream fileStream(m_filePath, std::ios::in | std::ios::binary);
        if (!fileStream)
            throw std::exception(String("IO error: Unable to open file '%'").arg(m_filePath).c_str());

        std::vector<int16_t> result(m_bufferByteSize / sizeof(int16_t), 0);
        m_reachedEnd = false;

        size_t bytesReadForNextBuffer = 0;
        fileStream.seekg(m_dataChunkPosition + std::streampos(m_currentPositionInDataChunk));

        do
        {
            fileStream.read(reinterpret_cast<char*>(&result[bytesReadForNextBuffer / sizeof(int16_t)]),
                            std::min(m_bufferByteSize - bytesReadForNextBuffer,
                                     m_dataChunkSize - m_currentPositionInDataChunk));
            auto const bytesRead = fileStream.gcount();
            bytesReadForNextBuffer += bytesRead;
            m_currentPositionInDataChunk += bytesRead;

            // If the end of the data chunk was reached reset to the data chunk start position
            if (fileStream.eof() ||
                m_currentPositionInDataChunk == m_dataChunkSize)
            {
                fileStream.clear();
                fileStream.seekg(m_dataChunkPosition);
                m_currentPositionInDataChunk = 0;
                m_reachedEnd = true;
            }

            if (fileStream.fail())
            {
                char errmsg[94];
                strerror_s(errmsg, 94, errno);
                throw std::exception(String("IO error: Error while reading file '%': %").arg(m_filePath).arg(errmsg).c_str());
            }
        } while (m_loopEnabled && bytesReadForNextBuffer < m_bufferByteSize);

        // Trim the buffer to the bytes that were actually read
        if (bytesReadForNextBuffer < m_bufferByteSize)
            result.resize(bytesReadForNextBuffer / sizeof(int16_t));

        return result;
    }