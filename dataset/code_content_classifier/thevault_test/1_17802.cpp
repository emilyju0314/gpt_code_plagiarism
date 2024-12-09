TEST(OUT_OF_PLACE, batch2) {
	SoftmaxTester()
		.batchSize(2)
		.channels(1000)
		.testOutput();
}