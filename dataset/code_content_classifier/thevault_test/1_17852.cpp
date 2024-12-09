TEST(OUT_OF_PLACE, conv8_relu) {
	VGG_A::conv8_relu()
		.batchSize(64)
		.testInputGradient();
}