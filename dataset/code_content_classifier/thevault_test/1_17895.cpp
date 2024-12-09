TEST(FT8x8, conv3) {
	OverFeat_Fast::conv3()
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8);
}