TEST(IFFT4_ACROSS_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(4)
		.simdWidth(1)
		.errorLimit(1.0e-7f);
	tester.testOptimizedComplex(nnp_ifft4_aos__scalar, nnp_ifft4_aos__ref);
}