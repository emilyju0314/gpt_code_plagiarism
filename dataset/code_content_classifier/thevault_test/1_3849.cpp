BOOST_AUTO_TEST_CASE_TEMPLATE(MeanVarianceNumSamplesComputationWithMasking, T, ImageTypes) {
  using namespace boost::accumulators;
  using Accumulator = accumulator_set<double, stats<tag::mean, tag::variance, tag::count>>;
  Accumulator acc1, acc2;

  setRNGSeed(1);
  auto numbers = generateRandomVector<T>(20, 0, 100);
  auto masks = generateRandomVector<uint8_t>(20, 0, 1);
  masks[0] = 1;  // make sure first number is averaged, otherwise boost accumulator gives NaN

  const int NUM_SAMPLES = 5;

  MeanImage mi1(false, 0);            // without variance, unlimited
  MeanImage mi2(true, 0);             // with variance, unlimited
  MeanImage mi3(false, NUM_SAMPLES);  // without variance, limited
  MeanImage mi4(true, NUM_SAMPLES);   // with variance, limited

  cv::Mat_<T> image(1, 1);
  cv::Mat_<uint8_t> mask(1, 1);

  for (size_t i = 0; i < numbers.size(); ++i) {
    const auto& n = numbers[i];
    const auto& m = masks[i];

    if (count(acc2) == NUM_SAMPLES) {
      acc2 = Accumulator();
    }

    if (m) {
      acc1(n);
      acc2(n);
    }

    image(0, 0) = n;
    mask(0, 0) = m;

    mi1.add(image, mask);
    BOOST_REQUIRE_CLOSE(mi1.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc1))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getMean(false).template at<double>(0, 0), mean(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getVariance().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getVarianceInverse().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi1.getNumSamples(false).template at<int>(0, 0), count(acc1));
    BOOST_REQUIRE_EQUAL(mi1.getNumSamples(true).template at<int>(0, 0), count(acc1));

    mi2.add(image, mask);
    BOOST_REQUIRE_CLOSE(mi2.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc1))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getMean(false).template at<double>(0, 0), mean(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getVariance().template at<double>(0, 0), variance(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getVarianceInverse().template at<double>(0, 0), div0(1.0, variance(acc1)),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi2.getNumSamples(false).template at<int>(0, 0), count(acc1));
    BOOST_REQUIRE_EQUAL(mi2.getNumSamples(true).template at<int>(0, 0), count(acc1));

    mi3.add(image, mask);
    BOOST_REQUIRE_CLOSE(mi3.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc2))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getMean(false).template at<double>(0, 0), mean(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getVariance().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getVarianceInverse().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi3.getNumSamples(false).template at<int>(0, 0), count(acc2));
    BOOST_REQUIRE_CLOSE(mi3.getNumSamples(true).template at<float>(0, 0), static_cast<float>(count(acc2)) / NUM_SAMPLES,
                        TOLERANCE_FLOAT);

    mi4.add(image, mask);
    BOOST_REQUIRE_CLOSE(mi4.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc2))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getMean(false).template at<double>(0, 0), mean(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getVariance().template at<double>(0, 0), variance(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getVarianceInverse().template at<double>(0, 0), div0(1.0, variance(acc2)),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi4.getNumSamples(false).template at<int>(0, 0), count(acc2));
    BOOST_REQUIRE_CLOSE(mi4.getNumSamples(true).template at<float>(0, 0), static_cast<float>(count(acc2)) / NUM_SAMPLES,
                        TOLERANCE_FLOAT);
  }
}