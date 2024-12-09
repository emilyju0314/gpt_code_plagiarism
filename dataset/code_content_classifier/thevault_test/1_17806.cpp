TEST(OUT_OF_PLACE, batch256) {
	SoftmaxTester()
		.multithreading(true)
		.batchSize(256)
		.channels(1000)
		.testOutput();
}