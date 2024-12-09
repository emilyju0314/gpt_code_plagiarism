TEST(OUT_OF_PLACE, batch1) {
	SoftmaxTester()
		.channels(1000)
		.testOutput();
}