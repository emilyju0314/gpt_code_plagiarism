TEST(MaxPooling2x2, pool1) {
	OverFeat_Fast::pool1()
		.batchSize(128)
		.testOutput();
}