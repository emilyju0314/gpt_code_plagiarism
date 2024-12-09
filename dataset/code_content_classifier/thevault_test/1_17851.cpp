TEST(OUT_OF_PLACE, conv5_relu) {
	VGG_A::conv5_relu()
		.batchSize(64)
		.testInputGradient();
}