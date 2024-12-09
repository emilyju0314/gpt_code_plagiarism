void CSMTP::encodeAttachment(CSMTP::EmailAttachment &attachment)
    {
        std::string line;
        // 7bit just copy
        if ((attachment.contentTransferEncoding.compare(kEncodingBase64) != 0))
        {
            std::ifstream attachmentFile(attachment.fileName);
            // As sending text file via email strip any host specific end of line and replace with <cr><lf>
            while (std::getline(attachmentFile, line))
            {
                if (line.back() == '\n')
                    line.pop_back();
                if (line.back() == '\r')
                    line.pop_back();
                attachment.encodedContents.push_back(line + kEOL);
            }
            // Base64
        }
        else
        {
            std::ifstream ifs{attachment.fileName, std::ios::binary};
            std::string buffer(kBase64EncodeBufferSize, ' ');
            ifs.seekg(0, std::ios::beg);
            while (ifs.good())
            {
                ifs.read(&buffer[0], kBase64EncodeBufferSize);
                encodeToBase64(buffer, line, ifs.gcount());
                attachment.encodedContents.push_back(line + kEOL);
                line.clear();
            }
        }
    }