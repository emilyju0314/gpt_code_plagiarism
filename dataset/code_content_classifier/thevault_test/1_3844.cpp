BOOST_AUTO_TEST_CASE(AddWeightsCompatibility) {
  cv::Size size(10, 5);

  // Weights (Mat CV_64F)
  {
    MeanImage mi1(false, 0);
    BOOST_REQUIRE_NO_THROW(mi1.addWeighted(cv::Mat(size, CV_8UC1), cv::Mat(size, CV_64FC1)));  // same size
    MeanImage mi2(false, 0);
    BOOST_REQUIRE_NO_THROW(mi2.addWeighted(cv::Mat(size, CV_32FC1), cv::Mat(size, CV_64FC1)));  // same size
    MeanImage mi3(false, 0);
    BOOST_REQUIRE_THROW(mi3.addWeighted(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_64FC1)),
                        radical::MatException);  // only for single-channel image
    MeanImage mi4(false, 0);
    BOOST_REQUIRE_THROW(mi4.addWeighted(cv::Mat(size, CV_32FC3), cv::Mat(size, CV_64FC1)),
                        radical::MatException);  // only for single-channel image
    MeanImage mi5(false, 0);
    BOOST_REQUIRE_THROW(mi5.addWeighted(cv::Mat(size, CV_16UC2), cv::Mat(size, CV_64FC1)),
                        radical::MatException);  // only for single-channel image
    MeanImage mi6(false, 0);
    BOOST_REQUIRE_THROW(mi6.addWeighted(cv::Mat(size, CV_8SC1), cv::Mat(1, 2, CV_64FC1)),
                        radical::MatException);  // wrong size
    MeanImage mi7(false, 0);
    BOOST_REQUIRE_THROW(mi7.addWeighted(cv::Mat(size, CV_32FC1), cv::Mat(3, 1, CV_64FC1)),
                        radical::MatException);  // wrong size
  }

  // Weights (Scalar CV_64F)
  {
    MeanImage mi1(false, 0);
    BOOST_REQUIRE_NO_THROW(mi1.addWeighted(cv::Mat(size, CV_8UC1), 1.0));
    MeanImage mi2(false, 0);
    BOOST_REQUIRE_NO_THROW(mi2.addWeighted(cv::Mat(size, CV_32FC1), 3));
    MeanImage mi3(false, 0);
    BOOST_REQUIRE_NO_THROW(mi3.addWeighted(cv::Mat(size, CV_32FC2), 10));
    MeanImage mi4(false, 0);
    BOOST_REQUIRE_NO_THROW(mi4.addWeighted(cv::Mat(size, CV_32FC1), cv::Mat(1, 1, CV_64FC1)));  // effectively scalar
    MeanImage mi5(false, 0);
    BOOST_REQUIRE_NO_THROW(mi5.addWeighted(cv::Mat(size, CV_32FC3), cv::Mat(1, 1, CV_64FC1)));  // effectively scalar
  }

  // Other types → exception
  {
    MeanImage mi1(false, 0);
    BOOST_REQUIRE_THROW(mi1.addWeighted(cv::Mat(size, CV_8UC1), cv::Mat(size, CV_8UC3)),
                        radical::MatException);  // wrong channels
    MeanImage mi2(false, 0);
    BOOST_REQUIRE_THROW(mi2.addWeighted(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_8UC2)),
                        radical::MatException);  // wrong channels
    MeanImage mi3(false, 0);
    BOOST_REQUIRE_THROW(mi3.addWeighted(cv::Mat(size, CV_8UC4), cv::Mat(size, CV_64FC2)),
                        radical::MatException);  // wrong channels
    MeanImage mi4(false, 0);
    BOOST_REQUIRE_THROW(mi4.addWeighted(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_16UC1)),
                        radical::MatException);  // wrong type
    MeanImage mi5(false, 0);
    BOOST_REQUIRE_THROW(mi5.addWeighted(cv::Mat(size, CV_32FC1), cv::Mat(size, CV_32FC1)),
                        radical::MatException);  // wrong type
  }
}