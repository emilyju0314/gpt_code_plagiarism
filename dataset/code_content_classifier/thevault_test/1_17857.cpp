TEST(MAX_POOLING_2x2, few_vertical_pools) {
	for (size_t imageHeight = 4; imageHeight <= 50; imageHeight += 2) {
		PoolingTester()
			.inputSize(imageHeight, 2)
			.poolingSize(2, 2)
			.poolingStride(2, 2)
			.iterations(100)
			.testOutput();
	}
}