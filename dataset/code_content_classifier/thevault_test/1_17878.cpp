TEST(FFT8_DUAL_REAL_WITHIN_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-7f);
	tester.testOptimizedDualReal(nnp_fft8_dualreal__avx2, nnp_fft8_dualreal__ref);
}