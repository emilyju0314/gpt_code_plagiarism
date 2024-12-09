TEST(FC, fc8) {
	OverFeat_Fast::fc8()
		.batchSize(128)
		.errorLimit(1.0e-5)
		.testOutput();
}