TEST(OUT_OF_PLACE, batch16) {
	SoftmaxTester()
		.batchSize(16)
		.channels(1000)
		.testOutput();
}