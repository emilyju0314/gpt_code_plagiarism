BOOST_AUTO_TEST_CASE(UninitializedState) {
  MeanImage mi(false, 0);
  BOOST_REQUIRE(mi.getMean().empty());
  BOOST_REQUIRE(mi.getVariance().empty());
  BOOST_REQUIRE(mi.getVarianceInverse().empty());
}