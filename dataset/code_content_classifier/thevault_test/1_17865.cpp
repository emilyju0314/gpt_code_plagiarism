TEST(MaxPooling2x2, pool3) {
	OverFeat_Fast::pool3()
		.batchSize(128)
		.testOutput();
}