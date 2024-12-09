BOOST_AUTO_TEST_CASE(GetMeanReturn) {
  MeanImage mi(false, 0);
  auto image = generateRandomImage(10, 5);
  mi.add(image);
  BOOST_CHECK_EQUAL(mi.getMean(true).size(), image.size());
  BOOST_CHECK_EQUAL(mi.getMean(true).type(), image.type());
  BOOST_CHECK_EQUAL(mi.getMean(false).size(), image.size());
  BOOST_CHECK_EQUAL(mi.getMean(false).depth(), CV_64F);
  BOOST_CHECK_EQUAL(mi.getMean(false).channels(), image.channels());
}