void MakeReport(void)
{
	printf("== Report on run ==\n");
	printf("-- Time series:\n");
	for (ts_index_t i = 0; i < TIME_SERIES_LEN; i++) {
		printf("%lld\t%.16g\n", i, T[i]);
	}
	printf("-- Parameters:\nLength of time series: %lld\nDiscord length: %lld\nDistance measure: %d\nDiscord starts at: %lld\n", TIME_SERIES_LEN, __n, D, discord_loc);
	printf("-- Heuristic search results:\nDiscord starts at: %lld (deviation is %lld)\nDiscord's nearest neighbor distance: %.16g\nExecution time: %.16g\n", bsf_loc, bsf_loc-discord_loc, bsf_dist, finish - start);
	printf("-- Brute force search results:\nDiscord starts at: %lld (deviation is %lld)\nDiscord's nearest neighbor distance: %.16g\nExecution time: %.16g\n", bruteforce_bsf_loc, bsf_loc - discord_loc, bruteforce_bsf_dist, finish_bruteforce - start_bruteforce);
	printf("== End of report ==\n");
}