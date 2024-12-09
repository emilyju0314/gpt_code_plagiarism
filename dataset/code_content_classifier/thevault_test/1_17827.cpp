TEST(MRxNR_4x24, single_input_channel) {
	FullyConnectedTester()
		.batchSize(4)
		.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}