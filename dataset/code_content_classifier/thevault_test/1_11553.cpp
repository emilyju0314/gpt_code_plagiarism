void CIMAP::generateTag()
    {
        std::ostringstream ss;
        ss << m_tagPrefix << std::setw(6) << std::setfill('0') << std::to_string(m_tagCount++);
        m_currentTag = ss.str();
    }