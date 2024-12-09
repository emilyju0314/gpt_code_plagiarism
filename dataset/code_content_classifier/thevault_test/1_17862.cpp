TEST(MAX_POOLING_2x2, few_channels) {
	PoolingTester tester;
	tester.inputSize(12, 12)
		.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100);
	for (size_t channels = 2; channels <= 5; channels++) {
		tester.channels(channels)
			.testOutput();
	}
}