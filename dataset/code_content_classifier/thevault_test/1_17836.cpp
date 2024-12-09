TEST(MRxNR_4x24, output_channels_remainder_subblock) {
	for (size_t outputChannels = 3 * 24 + 1; outputChannels < 4 * 24; outputChannels += 1) {
		FullyConnectedTester()
			.batchSize(4)
			.outputChannels(outputChannels)
			.iterations(100)
			.errorLimit(1.0e-5)
			.testOutput();
	}
}