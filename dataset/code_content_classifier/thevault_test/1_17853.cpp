TEST(OUT_OF_PLACE, fc6_relu) {
	VGG_A::fc6_relu()
		.batchSize(64)
		.testInputGradient();
}