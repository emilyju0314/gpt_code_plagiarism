TEST(IFFT8_ACROSS_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.simdWidth(8)
		.errorLimit(1.0e-7f);
	tester.testOptimizedComplex(nnp_ifft8_8aos__fma3, nnp_ifft8_aos__ref);
}