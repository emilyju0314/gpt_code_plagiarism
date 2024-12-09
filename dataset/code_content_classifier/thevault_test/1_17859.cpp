TEST(MAX_POOLING_2x2, indivisible_size) {
	PoolingTester()
		.inputSize(5, 5)
		.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100)
		.testOutput();
}