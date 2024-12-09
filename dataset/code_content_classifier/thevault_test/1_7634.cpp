void compute_lcp() {
	int len = 0;
	for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
		int s = REVSA[i];
		int j = SA[s - 1];
		for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
		LCP[s] = len;
	}
}