TEST(IFFT8_DUALREAL, match_real) {
	auto tester = FFTTester()
		.fftSize(8);
	tester.testDualComplexToReal(nnp_ifft8_dualreal__ref, nnp_ifft8_real__ref);
}