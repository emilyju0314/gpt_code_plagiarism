bool CZIP::add(const std::string &fileName, const std::string &zippedFileName)
    {
        if (!m_open)
        {
            throw Exception("ZIP archive has not been opened.");
        }
        // Check that an entry does not already exist
        for (auto &directoryEntry : m_zipCentralDirectory)
        {
            if (directoryEntry.fileName.compare(zippedFileName) == 0)
            {
                std::cerr << "File already present in archive [" << zippedFileName << "]" << std::endl;
                return (false);
            }
        }
        // Add file if it exists
        if (fileExists(fileName))
        {
            addFileHeaderAndContents(fileName, zippedFileName);
            return (true);
        }
        else
        {
            std::cerr << "File does not exist [" << fileName << "]" << std::endl;
        }
        return (false);
    }