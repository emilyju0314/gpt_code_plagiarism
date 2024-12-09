static long time_stamp(void)
{
#ifndef __linux__
	DWORD t;
	t = GetTickCount() / 1000;
	return (long) t;
#else
#include <time.h>
	return (long) time(NULL);
#endif
}