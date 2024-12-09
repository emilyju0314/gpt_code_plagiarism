TEST(OUT_OF_PLACE, batch128) {
	SoftmaxTester()
		.multithreading(true)
		.batchSize(128)
		.channels(1000)
		.testOutput();
}