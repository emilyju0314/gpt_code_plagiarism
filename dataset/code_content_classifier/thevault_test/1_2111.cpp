ts_index_t BruteForceDiscordSearch(const ts_element_t * _T, const ts_index_t n, ts_distance_t * bsf_dist)
{
	ts_index_t p, q;
	ts_distance_t d, nearest_neighbor_dist;

	*bsf_dist = 0;
	bsf_loc = (ts_index_t) NULL;

	for (p = 0; p < TIME_SERIES_LEN - n; p++) {
		nearest_neighbor_dist = INFTY;
		for (q = 0; q < TIME_SERIES_LEN - n; q++) {
			if (abs(p - q) >= n) {
				d = Distance(_T, n, p, q, D);
				assert(d >= 0);
				if (d < nearest_neighbor_dist) {
					nearest_neighbor_dist = d;
				}
			}
		}
		if (nearest_neighbor_dist > *bsf_dist) {
			*bsf_dist = nearest_neighbor_dist;
			bsf_loc = p;
		}
	}
	return bsf_loc;
}