TEST(Http2RandomTest, SkewedLowFullRange) {
  Http2Random random;
  std::set<size_t> values;
  for (int i = 0; i < 1000; i++) {
    values.insert(random.RandomSizeSkewedLow(3));
  }
  EXPECT_THAT(values, testing::ElementsAre(0, 1, 2, 3));
}