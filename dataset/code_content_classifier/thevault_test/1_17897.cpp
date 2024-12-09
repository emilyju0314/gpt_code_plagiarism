TEST(FT8x8, conv5) {
	OverFeat_Fast::conv5()
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8);
}