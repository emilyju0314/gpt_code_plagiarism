void CZIP::storeFile(const std::string &fileName, std::uint64_t fileSize)
    {
        std::ifstream fileStream(fileName, std::ios::binary);
        if (fileStream.fail())
        {
            throw Exception("Could not open source file for store.");
        }
        while (fileSize)
        {
            fileStream.read((char *)&m_zipInBuffer[0], std::min(fileSize, m_zipIOBufferSize));
            if (fileStream.fail())
            {
                throw Exception("Error reading source file to store in ZIP archive.");
            }
            writeZIPFile(m_zipInBuffer, fileStream.gcount());
            if (errorInZIPFile())
            {
                throw Exception("Error writing to ZIP archive.");
            }
            fileSize -= (std::min(fileSize, m_zipIOBufferSize));
        }
    }