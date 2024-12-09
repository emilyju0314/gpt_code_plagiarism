TEST(OUT_OF_PLACE, conv2_relu) {
	VGG_A::conv2_relu()
		.batchSize(64)
		.testInputGradient();
}