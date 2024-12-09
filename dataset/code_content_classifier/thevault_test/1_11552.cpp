void CIMAP::sendIMAPCommand(const std::string &command)
    {
        std::size_t bytesCopied{0};
        do
        {
            bytesCopied += m_imapSocket.write(&command[bytesCopied], command.length() - bytesCopied);
        } while ((bytesCopied < command.length()));
    }