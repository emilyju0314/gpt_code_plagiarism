TEST(FC, fc7) {
	OverFeat_Fast::fc7()
		.batchSize(128)
		.errorLimit(1.0e-5)
		.testOutput();
}