TEST(MRxNR_4x24, large_batch_size) {
	FullyConnectedTester()
		.batchSize(1024)
		.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}