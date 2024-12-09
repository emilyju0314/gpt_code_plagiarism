TEST(FFT8_REAL_ACROSS_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.simdWidth(1)
		.errorLimit(1.0e-7f);
	tester.testOptimizedReal(nnp_fft8_real__scalar, nnp_fft8_real__ref);
}