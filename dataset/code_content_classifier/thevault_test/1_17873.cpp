TEST(IFFT8_REAL, match_complex) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-3f);
	tester.testComplexToReal(nnp_ifft8_real__ref, nnp_ifft8_aos__ref);
}