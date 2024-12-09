TEST(OUT_OF_PLACE, conv1_relu) {
	VGG_A::conv1_relu()
		.batchSize(64)
		.testInputGradient();
}