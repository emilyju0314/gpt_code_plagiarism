TEST(FFT2_SOA, match_aos) {
	auto tester = FFTTester()
		.fftSize(2)
		.errorLimit(1.0e-7f);
	tester.testSoa(nnp_fft2_soa__ref, nnp_fft2_aos__ref);
}