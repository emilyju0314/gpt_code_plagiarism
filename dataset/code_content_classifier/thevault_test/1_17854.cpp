TEST(OUT_OF_PLACE, fc8_relu) {
	VGG_A::fc8_relu()
		.batchSize(64)
		.testInputGradient();
}