TEST_F(ResultIteratorTest, GreyTest) {
  SetImage("8087_054.3G.tif");
  // Just run layout analysis.
  PageIterator *it = api_.AnalyseLayout();
  EXPECT_FALSE(it == nullptr);
  // The images should rebuild almost perfectly.
  VerifyRebuilds(600, 600, 600, 600, 600, it);
  delete it;
}