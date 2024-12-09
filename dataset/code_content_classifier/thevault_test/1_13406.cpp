const std::string Utils::getCurrentTime(const std::string& format)
{
    struct tm lt;
    time_t now = time(NULL);
    if (localtime_r(&now, &lt) == NULL)
    {
        throw Exception(__FILE__, __LINE__,
                             "Error %d in localtime_r(): %s",
                             errno, strerror(errno));
    }
    char buff[512];
    strftime(buff, sizeof(buff) - 1, format.c_str(), &lt);
    return std::string(buff);
}