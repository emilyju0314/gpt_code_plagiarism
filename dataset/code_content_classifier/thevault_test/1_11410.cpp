CRedirect::CRedirect(std::ostream &outStream, const std::string &outfileName, std::ios_base::openmode mode)
    {
        m_savedStream = &outStream;
        change(outfileName, mode);
    }