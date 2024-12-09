TEST(FFT8_WITHIN_ROWS, match_reference) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-8f);
	tester.testOptimizedComplex(nnp_fft8_soa__avx2, nnp_fft8_soa__ref);
}