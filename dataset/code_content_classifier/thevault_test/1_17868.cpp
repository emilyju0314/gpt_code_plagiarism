TEST(FFT2_AOS, reference_sample) {
	auto tester = FFTTester()
		.fftSize(2)
		.errorLimit(1.0e-6f);
	tester.testForwardAosSamples(nnp_fft2_aos__ref,
		samples::fft2::input, samples::fft2::output);
}