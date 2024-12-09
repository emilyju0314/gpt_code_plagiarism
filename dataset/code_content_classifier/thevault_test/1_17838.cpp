TEST(FT8x8, single_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testKernelGradient(nnp_convolution_algorithm_ft8x8);
}