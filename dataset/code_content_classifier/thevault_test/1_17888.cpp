TEST(FT8x8, small_batch) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t batchSize = 2; batchSize <= 5; batchSize++) {
		tester.batchSize(batchSize).testOutput(nnp_convolution_algorithm_ft8x8);
	}
}