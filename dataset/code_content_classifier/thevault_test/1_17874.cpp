TEST(FFT8_DUALREAL, match_real) {
	auto tester = FFTTester()
		.fftSize(8);
	tester.testDualRealToComplex(nnp_fft8_dualreal__ref, nnp_fft8_real__ref);
}