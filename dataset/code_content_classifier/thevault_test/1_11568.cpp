std::string CSMTP::getMailFull(void)
    {
        std::string mailMessage;
        buildMailPayload();
        for (auto &line : m_mailPayload)
        {
            mailMessage.append(line);
        }
        m_mailPayload.clear();
        return (mailMessage);
    }