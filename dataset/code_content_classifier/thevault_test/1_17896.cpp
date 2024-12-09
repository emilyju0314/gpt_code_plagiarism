TEST(FT8x8, conv4) {
	OverFeat_Fast::conv4()
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8);
}