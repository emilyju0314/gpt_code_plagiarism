bool FindFile::FindNext()
    {
        if (m_pDirHeader && m_itFile != m_pDirHeader->GetFileEnd())
        {
            ++m_itFile;
            return SkipNonMatchingFiles();
        }
        else
        {
            return false;
        }
    }