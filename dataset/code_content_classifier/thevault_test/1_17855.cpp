TEST(MAX_POOLING_2x2, single_pool) {
	PoolingTester()
		.inputSize(2, 2)
		.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100)
		.testOutput();
}