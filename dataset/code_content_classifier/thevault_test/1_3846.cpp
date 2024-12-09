BOOST_AUTO_TEST_CASE(GetVarianceReturn) {
  auto image = generateRandomImage(10, 5);

  // Variance computation enabled
  {
    MeanImage mi(true, 0);
    mi.add(image);
    BOOST_CHECK_EQUAL(mi.getVariance().size(), image.size());
    BOOST_CHECK_EQUAL(mi.getVariance().depth(), CV_64F);
    BOOST_CHECK_EQUAL(mi.getVariance().channels(), image.channels());
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().size(), image.size());
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().depth(), CV_64F);
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().channels(), image.channels());
  }

  // Variance computation disabled, should be the same
  {
    MeanImage mi(false, 0);
    mi.add(image);
    BOOST_CHECK_EQUAL(mi.getVariance().size(), image.size());
    BOOST_CHECK_EQUAL(mi.getVariance().depth(), CV_64F);
    BOOST_CHECK_EQUAL(mi.getVariance().channels(), image.channels());
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().size(), image.size());
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().depth(), CV_64F);
    BOOST_CHECK_EQUAL(mi.getVarianceInverse().channels(), image.channels());
  }
}