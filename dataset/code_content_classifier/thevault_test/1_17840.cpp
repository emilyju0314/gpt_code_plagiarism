TEST(FT8x8, multi_tile) {
	ConvolutionTester()
		.inputSize(13, 13)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testKernelGradient(nnp_convolution_algorithm_ft8x8);
}