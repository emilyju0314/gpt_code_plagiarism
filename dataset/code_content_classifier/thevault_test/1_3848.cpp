BOOST_AUTO_TEST_CASE_TEMPLATE(MeanVarianceNumSamplesComputation, T, ImageTypes) {
  using namespace boost::accumulators;
  using Accumulator = accumulator_set<double, stats<tag::mean, tag::variance, tag::count>>;
  Accumulator acc1, acc2;

  setRNGSeed(0);
  auto numbers = generateRandomVector<T>(10, 0, 100);

  const int NUM_SAMPLES = 5;

  MeanImage mi1(false, 0);            // without variance, unlimited
  MeanImage mi2(true, 0);             // with variance, unlimited
  MeanImage mi3(false, NUM_SAMPLES);  // without variance, limited
  MeanImage mi4(true, NUM_SAMPLES);   // with variance, limited
  cv::Mat_<T> image(1, 1);

  for (size_t i = 0; i < numbers.size(); ++i) {
    const auto& n = numbers[i];
    int j = i % NUM_SAMPLES;

    if (j == 0)
      acc2 = Accumulator();

    acc1(n);
    acc2(n);
    image(0, 0) = n;

    mi1.add(image);
    BOOST_REQUIRE_CLOSE(mi1.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc1))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getMean(false).template at<double>(0, 0), mean(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getVariance().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi1.getVarianceInverse().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi1.getNumSamples(false).template at<int>(0, 0), count(acc1));
    BOOST_REQUIRE_EQUAL(mi1.getNumSamples(true).template at<int>(0, 0), count(acc1));

    mi2.add(image);
    BOOST_REQUIRE_CLOSE(mi2.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc1))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getMean(false).template at<double>(0, 0), mean(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getVariance().template at<double>(0, 0), variance(acc1), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi2.getVarianceInverse().template at<double>(0, 0), div0(1.0, variance(acc1)),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi2.getNumSamples(false).template at<int>(0, 0), count(acc1));
    BOOST_REQUIRE_EQUAL(mi2.getNumSamples(true).template at<int>(0, 0), count(acc1));

    mi3.add(image);
    BOOST_REQUIRE_CLOSE(mi3.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc2))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getMean(false).template at<double>(0, 0), mean(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getVariance().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi3.getVarianceInverse().template at<double>(0, 0), 0, TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi3.getNumSamples(false).template at<int>(0, 0), j + 1);
    BOOST_REQUIRE_CLOSE(mi3.getNumSamples(true).template at<float>(0, 0), (1.0f + j) / NUM_SAMPLES, TOLERANCE_FLOAT);

    mi4.add(image);
    BOOST_REQUIRE_CLOSE(mi4.getMean(true).template at<T>(0, 0), static_cast<double>(cv::saturate_cast<T>(mean(acc2))),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getMean(false).template at<double>(0, 0), mean(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getVariance().template at<double>(0, 0), variance(acc2), TOLERANCE_DOUBLE);
    BOOST_REQUIRE_CLOSE(mi4.getVarianceInverse().template at<double>(0, 0), div0(1.0, variance(acc2)),
                        TOLERANCE_DOUBLE);
    BOOST_REQUIRE_EQUAL(mi4.getNumSamples(false).template at<int>(0, 0), j + 1);
    BOOST_REQUIRE_CLOSE(mi4.getNumSamples(true).template at<float>(0, 0), (1.0f + j) / NUM_SAMPLES, TOLERANCE_FLOAT);
  }
}