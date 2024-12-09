TEST(MRxNR_4x24, output_channels_subblock) {
	FullyConnectedTester tester;
	tester.batchSize(4)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t outputChannels = 1; outputChannels < 24; outputChannels += 1) {
		tester.outputChannels(outputChannels)
			.testOutput();
	}
}