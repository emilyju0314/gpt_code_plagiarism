void compute_reverse_sa() {
	for(int i = 0; i <= AN; i++) {
		REVSA[SA[i]] = i;
	}
}