std::uint32_t CZIP::extractFile(const std::string &fileName, std::uint64_t fileSize)
    {
        std::uint32_t crc;
        crc = crc32(0L, Z_NULL, 0);
        std::ofstream fileStream(fileName, std::ios::binary | std::ios::trunc);
        if (fileStream.fail())
        {
            throw Exception("Could not open destination file for extract.");
        }
        while (fileSize)
        {
            readZIPFile(m_zipInBuffer, std::min(fileSize, m_zipIOBufferSize));
            if (errorInZIPFile())
            {
                throw Exception("Error in reading ZIP archive file.");
            }
            crc = crc32(crc, &m_zipInBuffer[0], readCountZIPFile());
            fileStream.write((char *)&m_zipInBuffer[0], readCountZIPFile());
            if (fileStream.fail())
            {
                throw Exception("Error in writing extracted file.");
            }
            fileSize -= (std::min(fileSize, m_zipIOBufferSize));
        }
        return (crc);
    }