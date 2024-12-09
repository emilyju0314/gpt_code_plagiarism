BOOST_AUTO_TEST_CASE(GetNumSamplesReturn) {
  auto image = generateRandomImage(10, 5);

  // Unlimited accumulation
  {
    MeanImage mi(false, 0);
    mi.add(image);
    BOOST_CHECK_EQUAL(mi.getNumSamples(false).size(), image.size());
    BOOST_CHECK_EQUAL(mi.getNumSamples(false).type(), CV_32SC1);
    BOOST_CHECK_EQUAL(mi.getNumSamples(true).size(), image.size());
    BOOST_CHECK_EQUAL(mi.getNumSamples(true).type(), CV_32SC1);
  }

  // With limit
  {
    MeanImage mi(false, 10);
    mi.add(image);
    BOOST_CHECK_EQUAL(mi.getNumSamples(false).size(), image.size());
    BOOST_CHECK_EQUAL(mi.getNumSamples(false).type(), CV_32SC1);
    BOOST_CHECK_EQUAL(mi.getNumSamples(true).size(), image.size());
    BOOST_CHECK_EQUAL(mi.getNumSamples(true).type(), CV_32FC1);
  }
}