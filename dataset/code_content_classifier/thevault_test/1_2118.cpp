void train(series_t timeSeries, const long size) {
	double start = omp_get_wtime();
	m_trained = false;
	double mean = 0;
	double stdev = DBL_MIN;
	if (size < 2) 
	{
		mean = timeSeries[0];
		stdev = DBL_MIN;
	}
	else
	{
		size_t n = 0;
		double M2 = 0;
		#pragma acc kernels device_type(nvidia)
		for (long i = 0; i < size; i++) {
			++n;
			double delta = timeSeries[i] - mean;
			mean += delta / n;
			M2 += delta * (timeSeries[i] - mean);
		}
		stdev = sqrt(M2 / (n - 1));
	}
	if (stdev == 0)
	{
		stdev = DBL_MIN;
	}
	m_baseline_mean = mean;
	m_baseline_stdev = stdev;
	std::cout << mean << " " << stdev << std::endl;
	m_trained = true;
	double end = omp_get_wtime();
	*_time += (end - start);
}