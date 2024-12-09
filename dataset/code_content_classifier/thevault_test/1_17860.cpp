TEST(MAX_POOLING_2x2, implicit_padding) {
	PoolingTester tester;
	tester.poolingSize(2, 2)
		.poolingStride(2, 2)
		.iterations(100);
	const size_t inputHeight = 24;
	const size_t inputWidth = 24;
	for (size_t paddingTop = 0; paddingTop < tester.poolingHeight(); paddingTop++) {
		for (size_t paddingLeft = 0; paddingLeft < tester.poolingWidth(); paddingLeft++) {
			for (size_t paddingBottom = 0; paddingBottom < tester.poolingHeight(); paddingBottom++) {
				for (size_t paddingRight = 0; paddingRight < tester.poolingWidth(); paddingRight++) {
					tester.inputSize(
							inputHeight - paddingTop - paddingBottom,
							inputWidth - paddingLeft - paddingRight)
						.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testOutput();
				}
			}
		}
	}
}