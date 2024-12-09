TEST(MAX_POOLING_2x2, few_horizontal_pools) {
	for (size_t imageWidth = 4; imageWidth <= 50; imageWidth += 2) {
		PoolingTester()
			.inputSize(2, imageWidth)
			.poolingSize(2, 2)
			.poolingStride(2, 2)
			.iterations(100)
			.testOutput();
	}
}