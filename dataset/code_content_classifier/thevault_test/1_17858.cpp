TEST(MAX_POOLING_2x2, large_image) {
	PoolingTester()
		.inputSize(128, 128)
		.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100)
		.testOutput();
}