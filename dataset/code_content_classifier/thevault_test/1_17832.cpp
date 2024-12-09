TEST(MRxNR_4x24, batch_remainder_subblock) {
	for (size_t batchSize = 12; batchSize < 16; batchSize += 1) {
		FullyConnectedTester()
			.batchSize(batchSize)
			.outputChannels(24)
			.iterations(100)
			.errorLimit(1.0e-5)
			.testOutput();
	}
}