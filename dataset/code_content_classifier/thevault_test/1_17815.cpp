TEST(IFFT8_DUAL_REAL_WITHIN_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-7f);
	tester.testOptimizedDualReal(nnp_ifft8_dualreal__scalar, nnp_ifft8_dualreal__ref);
}