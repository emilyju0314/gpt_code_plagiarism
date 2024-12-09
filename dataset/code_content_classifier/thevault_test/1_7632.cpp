void prep_string() {
	int v = AN = 0;
	memset(cnt, 0, 256 * sizeof(int));
	for(int i = 0; i < (int) SS.size(); ++AN, i++) {
		cnt[SS[i]]++;
		cnt[i] = SA[i] = pos[i] = REVSA[i] = LCP[i] = 0;
	}
	for(int i = 0; i < AN; i++) cnt[SS[i]]++;
	for(int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
	for(int i = 0; i < AN; i++) A[i] = cnt[SS[i]];
}