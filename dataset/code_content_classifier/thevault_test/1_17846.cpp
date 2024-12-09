TEST(FT8x8, non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(9, 10)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testKernelGradient(nnp_convolution_algorithm_ft8x8);
}