TEST(IMPLICIT_GEMM, conv1) {
	OverFeat_Fast::conv1()
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_implicit_gemm);
}