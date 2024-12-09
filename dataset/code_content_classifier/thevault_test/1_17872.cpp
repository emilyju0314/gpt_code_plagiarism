TEST(FFT8_REAL, match_complex) {
	auto tester = FFTTester()
		.fftSize(8)
		.errorLimit(1.0e-3f);
	tester.testRealToComplex(nnp_fft8_real__ref, nnp_fft8_aos__ref);
}