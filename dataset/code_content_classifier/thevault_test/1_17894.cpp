TEST(FT8x8, conv2) {
	OverFeat_Fast::conv2()
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8);
}