TEST(MRxNR_4x24, many_input_channels) {
	FullyConnectedTester()
		.batchSize(4)
		.inputChannels(1024)
		.outputChannels(24)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}