bool FindDir::FindNext()
    {
        if (m_pDirHeader && m_itDir != m_pDirHeader->GetDirEnd())
        {
            ++m_itDir;
            return SkipNonMatchingDirs();
        }
        else
        {
            return false;
        }
    }