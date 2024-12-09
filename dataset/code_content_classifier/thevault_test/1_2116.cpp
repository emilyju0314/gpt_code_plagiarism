series_t normalize(series_t timeSeries, const long size)
{
	double start = omp_get_wtime();
	#pragma acc parallel vector_length(32)
	#pragma acc loop gang worker
	for (size_t i = 0; i < size; i++) {
		// normalize around baseline
		timeSeries[i] = (timeSeries[i] - m_baseline_mean) / m_baseline_stdev;
	}
	double end = omp_get_wtime();
	*_time += (end - start);
	return timeSeries;
}