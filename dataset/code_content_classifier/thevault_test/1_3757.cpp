bool CSystem::GetCurrentTimeAndDate(int *year, int *month, int *dayOfWeek, int *day, int *hour, int *minute, int *second)
{
	time_t t = time( NULL );
	struct tm *now = localtime( &t );
	if ( now )
	{
		if ( year ) *year = now->tm_year + 1900;
		if ( month ) *month = now->tm_mon + 1;
		if ( dayOfWeek ) *dayOfWeek = now->tm_wday;
		if ( day ) *day = now->tm_mday;
		if ( hour ) *hour = now->tm_hour;
		if ( minute ) *minute = now->tm_min;
		if ( second )  *second = now->tm_sec;
	return true;
}
	return false;
}