void SetParameters(void)
{
	//TIME_SERIES_LEN = 1 << 10;
	TIME_SERIES_LEN = 1024;
	assert(TIME_SERIES_LEN > 0);

	//n = 1 << 5;
	__n = 64;
	assert(__n > 0 && __n < TIME_SERIES_LEN);

	D = EUQLID2;
	assert(D == EUQLID2);

	discord_length = __n;
	// Generate time series with random discord's starting point
		srand(time(NULL));
		discord_loc = rand() % (TIME_SERIES_LEN - __n);
	// discord_loc = TIME_SERIES_LEN - n;
	assert(discord_loc >= 0 && discord_loc <= TIME_SERIES_LEN - __n);
}