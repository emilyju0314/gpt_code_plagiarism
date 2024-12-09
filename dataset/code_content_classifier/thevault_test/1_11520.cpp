void CZIP::create(void)
    {
        if (m_open)
        {
            throw Exception("ZIP archive should not be open.");
        }
        EOCentralDirectoryRecord zipEOCentralDirectory;
        openZIPFile(m_zipFileName, std::ios::binary | std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
        putZIPRecord(zipEOCentralDirectory);
        closeZIPFile();
    }