const std::string Utils::time2Str(time_t time)
{
    std::string result = "";

    try
    {
        const time_t SECOND = 1;
        const time_t MINUTE = SECOND * 60;
        const time_t HOUR = MINUTE*60;
        const time_t DAY = HOUR*24;
        time_t day = time / DAY;
        if (day > 0)
        {
            time -= day * DAY;
            result += boost::lexical_cast<std::string>(day);
            result += " d. ";
        }
        int hour = time / HOUR;
        if (hour > 0)
        {
            time -= hour * HOUR;
        }
        int minute = time / MINUTE;
        if (minute > 0)
        {
            time -= minute * MINUTE;
        }
        int second = time;
        char buff[128];
        snprintf(buff, sizeof(buff) - 1, "%.2d:%.2d:%.2d",
                 hour, minute, second);
        result += buff;
    }
    catch(const boost::bad_lexical_cast&)
    {
        throw Exception(__FILE__, __LINE__, err::BADLEXCAST);
    }
    return result;
}