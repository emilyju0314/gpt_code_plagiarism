TEST(FC, fc6) {
	OverFeat_Fast::fc6()
		.batchSize(128)
		.errorLimit(1.0e-5)
		.testOutput();
}