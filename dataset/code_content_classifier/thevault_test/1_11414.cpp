void CRedirect::restore()
    {
        if (m_outputBuffer)
        {
            m_savedStream->rdbuf(m_outputBuffer);
        }
        if (m_newFileStream)
        {
            m_newFileStream->close();
        }
        if (m_savedStdOutErr)
        {
            fclose(m_savedStdOutErr);
        }
    }