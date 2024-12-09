TEST(FT8x8, input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput(nnp_convolution_algorithm_ft8x8);
}