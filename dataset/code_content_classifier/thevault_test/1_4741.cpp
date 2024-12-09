size_t binomial_coefficient(const size_t n, const size_t k) {
	// The regular identity of
	//           n!
	// C(n, k) = -------------
	//           k! * (n - k)!
	//
	// produces problems with huge numbers, instead we can use the identity
	// C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
	//
	// and build the permutations from the ground from C(0, 0) to C(n, k)
	// storing previous calculations in a vector
	// where C(n, k) is stored at C[n][k] (or C.at(n).at(k))
	std::vector<std::vector<size_t>> C(n + 1);
	for (std::vector<size_t>& vec : C) {
		vec.resize(k + 1);
	}
	for (size_t i = 0; i <= n; i++) {
		for (size_t j = 0; j <= std::min(i, k); j++) {
			if (j == 0 || j == i) {
				C.at(i).at(j) = 1;
			} else {
				C.at(i).at(j) = C.at(i - 1).at(j - 1) + C.at(i - 1).at(j);
			}
		}
	}
	return C.at(n).at(k);
}