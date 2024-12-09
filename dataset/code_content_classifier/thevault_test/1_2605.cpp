CVCardDateTime CVCardDateTime::GetNow()
{
	// Get from posix time
	time_t now = time(NULL);
	struct tm* now_tm = std::localtime(&now);
	
	return CVCardDateTime(now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday, now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);
}