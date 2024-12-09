ts_distance_t Distance(const ts_element_t * _T, const ts_index_t n, const ts_index_t p, const ts_index_t q, ts_distance_kind_t D)
{
	ts_distance_t d = 0;

	assert((p>=0) && (p<=TIME_SERIES_LEN-n));
	assert((q>=0) && (q<=TIME_SERIES_LEN-n));
	assert(abs(p-q)>=n);
	switch (D)
	{
	case EUQLID2:
		for (ts_index_t i = 0; i < n; i++) {
			d += ((_T[p+i] - _T[q+i])*(_T[p+i] - _T[q+i]));
		}
		break;
	case MANHATTAN:
		assert(FALSE);
		break;
	default:
		assert(FALSE);
		break;
	}
	return d;
}