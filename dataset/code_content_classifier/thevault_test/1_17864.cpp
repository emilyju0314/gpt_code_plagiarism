TEST(MaxPooling2x2, pool2) {
	OverFeat_Fast::pool2()
		.batchSize(128)
		.testOutput();
}