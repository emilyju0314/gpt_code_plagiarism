TEST(IFFT8_REAL_ACROSS_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.simdWidth(8)
		.errorLimit(1.0e-7f);
	tester.testOptimizedReal(nnp_ifft8_8real__fma3, nnp_ifft8_real__ref);
}