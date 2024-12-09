TEST(MAX_POOLING_2x2, small_batch) {
	PoolingTester tester;
	tester.inputSize(12, 12)
		.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100);
	for (size_t batchSize = 2; batchSize <= 5; batchSize++) {
		tester.batchSize(batchSize)
			.testOutput();
	}
}