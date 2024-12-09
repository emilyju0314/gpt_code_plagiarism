word saxify(series_t sequence, const int n)
{
	assert(n > 0);
	assert(sequence !=  NULL);
	// create PAA representation of given subsequence
	series_t paa = PAA(sequence, n);
	word syms = (word)__align_malloc(wordLength * sizeof(symbol));
	// map to symbols.
	for (size_t i = 0; i < wordLength; ++i) {
		int cnt = 0;
		for (int j = 0; j < m_alphabet_size - 1; j++)
		{
			if (paa[i] >= m_cutpoints[j])
			{
				cnt++;
			}
		}
		syms[i] = alphabet[cnt];
	}
	return syms;
}