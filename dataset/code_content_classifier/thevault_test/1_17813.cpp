TEST(IFFT8_WITHIN_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-8f);
	tester.testOptimizedComplex(nnp_ifft8_soa__scalar, nnp_ifft8_soa__ref);
}