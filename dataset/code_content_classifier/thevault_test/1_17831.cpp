TEST(MRxNR_4x24, small_batch_size) {
	FullyConnectedTester()
		.batchSize(12)
		.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}