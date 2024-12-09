const std::string CSMTP::currentDateAndTime(void)
    {
        std::time_t rawtime{0};
        struct std::tm *info{
            0};
        std::string buffer(80, ' ');
        std::time(&rawtime);
        info = std::localtime(&rawtime);
        buffer.resize(std::strftime(&buffer[0], buffer.length(), "%a, %d %b %Y %H:%M:%S %z", info));
        return (buffer);
    }