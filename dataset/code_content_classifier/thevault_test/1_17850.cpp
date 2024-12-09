TEST(OUT_OF_PLACE, conv3_relu) {
	VGG_A::conv3_relu()
		.batchSize(64)
		.testInputGradient();
}