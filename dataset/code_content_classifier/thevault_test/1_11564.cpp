void CSMTP::buildMailPayload(void)
    {
        bool bAttachments{!m_attachedFiles.empty()};
        // Email header.
        m_mailPayload.emplace_back("Date: " + currentDateAndTime() + kEOL);
        m_mailPayload.emplace_back("To: " + m_addressTo + kEOL);
        m_mailPayload.emplace_back("From: " + m_addressFrom + kEOL);
        if (!m_addressCC.empty())
        {
            m_mailPayload.emplace_back("cc: " + m_addressCC + kEOL);
        }
        m_mailPayload.emplace_back("Subject: " + m_mailSubject + kEOL);
        m_mailPayload.emplace_back(std::string("MIME-Version: 1.0") + kEOL);
        if (!bAttachments)
        {
            m_mailPayload.emplace_back(std::string("Content-Type: text/plain; charset=UTF-8") + kEOL);
            m_mailPayload.emplace_back(std::string("Content-Transfer-Encoding: 7bit") + kEOL);
        }
        else
        {
            m_mailPayload.emplace_back(std::string("Content-Type: multipart/mixed;") + kEOL);
            m_mailPayload.emplace_back(std::string(R"(     boundary=")") + kMimeBoundary + R"(")" + kEOL);
        }
        m_mailPayload.emplace_back(kEOL); // EMPTY LINE
        if (bAttachments)
        {
            m_mailPayload.emplace_back(std::string("--") + kMimeBoundary + kEOL);
            m_mailPayload.emplace_back(std::string("Content-Type: text/plain") + kEOL);
            m_mailPayload.emplace_back(std::string("Content-Transfer-Encoding: 7bit") + kEOL);
            m_mailPayload.emplace_back(kEOL); // EMPTY LINE
        }
        // Message body
        for (auto &str : m_mailMessage)
        {
            m_mailPayload.emplace_back(str + kEOL);
        }
        if (bAttachments)
        {
            m_mailPayload.emplace_back(kEOL); // EMPTY LINE
            buildAttachments();
            m_mailPayload.emplace_back(std::string("--") + kMimeBoundary + "--" + kEOL);
        }
    }