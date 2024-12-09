TEST(MRxNR_4x24, few_output_channels) {
	FullyConnectedTester()
		.batchSize(4)
		.outputChannels(72)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}