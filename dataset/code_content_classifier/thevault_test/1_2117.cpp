series_t PAA(series_t sequence, const int n)
{
	item_t* paa = (series_t)__align_malloc(wordLength * sizeof(item_t));;
	for (int i = 0; i < wordLength; i++)
	{
		paa[i] = 0;
	}
	double start = omp_get_wtime();
	long paa_window = n / m_string_size;
	#pragma acc parallel loop collapse(2) device_type(nvidia)
	for (int i = 0; i < wordLength; i++)
	{
		for (long j = paa_window * i; j < paa_window * (i + 1); j++)
		{
			#pragma acc atomic
			paa[i] += sequence[j];
		}
		paa[i] *= 1.0f * m_string_size / n;
	}
	double end = omp_get_wtime();
	*_time += (end - start);
	return paa;
}