TEST(MRxNR_4x24, batch_subblock) {
	FullyConnectedTester tester;
	tester.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t batchSize = 1; batchSize < 4; batchSize += 1) {
		tester.batchSize(batchSize)
			.testOutput();
	}
}