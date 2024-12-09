TEST(FT8x8, non_square_kernel) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(2, 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testKernelGradient(nnp_convolution_algorithm_ft8x8);
}