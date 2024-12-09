TEST(IFFT2_SOA, match_aos) {
	auto tester = FFTTester()
		.fftSize(2)
		.errorLimit(1.0e-7f);
	tester.testSoa(nnp_ifft2_soa__ref, nnp_ifft2_aos__ref);
}