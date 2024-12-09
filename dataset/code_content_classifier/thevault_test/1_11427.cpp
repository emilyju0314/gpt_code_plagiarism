void CZIPIO::openZIPFile(const std::string &fileName, std::ios_base::openmode mode)
    {
        m_zipFileStream.open(fileName, mode);
        if (m_zipFileStream.fail())
        {
            throw Exception("Could not open ZIP archive " + fileName);
        }
    }