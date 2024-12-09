TEST(MRxNR_4x24, few_input_channels) {
	FullyConnectedTester()
		.batchSize(4)
		.inputChannels(13)
		.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}