TEST(FFT4_ACROSS_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(4)
		.simdWidth(8)
		.errorLimit(1.0e-8f);
	tester.testOptimizedComplex(nnp_fft4_8aos__fma3, nnp_fft4_aos__ref);
}