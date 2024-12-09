TEST(OUT_OF_PLACE, batch64) {
	SoftmaxTester()
		.batchSize(64)
		.channels(1000)
		.testOutput();
}