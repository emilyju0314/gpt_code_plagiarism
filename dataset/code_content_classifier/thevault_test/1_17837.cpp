TEST(MRxNR_4x24, many_output_channels) {
	FullyConnectedTester()
		.batchSize(4)
		.outputChannels(1200)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testOutput();
}