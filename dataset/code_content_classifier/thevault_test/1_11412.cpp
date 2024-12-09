void CRedirect::change(const std::string &outfileName, std::ios_base::openmode mode)
    {
        m_newFileStream = std::make_unique<std::ofstream>(outfileName, mode);
        m_outputBuffer = m_savedStream->rdbuf();
        m_savedStream->rdbuf((m_newFileStream)->rdbuf());
    }