TEST(FFT2_AOS, forward_and_inverse) {
	auto tester = FFTTester()
		.fftSize(2)
		.iterations(10000)
		.errorLimit(1.0e-4f);
	tester.testForwardAndInverseAos(nnp_fft2_aos__ref, nnp_ifft2_aos__ref);
}