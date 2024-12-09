BOOST_AUTO_TEST_CASE(AddMaskCompatibility) {
  cv::Size size(10, 5);

  // Masks (CV_8UC1)
  {
    MeanImage mi1(false, 0);
    BOOST_REQUIRE_NO_THROW(mi1.add(cv::Mat(size, CV_8UC1), cv::Mat(size, CV_8UC1)));  // same size
    MeanImage mi2(false, 0);
    BOOST_REQUIRE_NO_THROW(mi2.add(cv::Mat(size, CV_32FC1), cv::Mat(size, CV_8UC1)));  // same size
    MeanImage mi3(false, 0);
    BOOST_REQUIRE_NO_THROW(mi3.add(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_8UC1)));  // same size
    MeanImage mi4(false, 0);
    BOOST_REQUIRE_NO_THROW(mi4.add(cv::Mat(size, CV_32FC3), cv::Mat(size, CV_8UC1)));  // same size
    MeanImage mi5(false, 0);
    BOOST_REQUIRE_NO_THROW(mi5.add(cv::Mat(size, CV_16UC2), cv::Mat(size, CV_8UC1)));  // same size
    MeanImage mi6(false, 0);
    BOOST_REQUIRE_THROW(mi6.add(cv::Mat(size, CV_8SC1), cv::Mat(1, 1, CV_8UC1)), radical::MatException);  // wrong size
    MeanImage mi7(false, 0);
    BOOST_REQUIRE_THROW(mi7.add(cv::Mat(size, CV_32FC2), cv::Mat(1, 1, CV_8UC1)), radical::MatException);  // wrong size
  }

  // Other types → exception
  {
    MeanImage mi1(false, 0);
    BOOST_REQUIRE_THROW(mi1.add(cv::Mat(size, CV_8UC1), cv::Mat(size, CV_8UC3)),
                        radical::MatException);  // wrong channels
    MeanImage mi2(false, 0);
    BOOST_REQUIRE_THROW(mi2.add(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_8UC2)),
                        radical::MatException);  // wrong channels
    MeanImage mi3(false, 0);
    BOOST_REQUIRE_THROW(mi3.add(cv::Mat(size, CV_8UC4), cv::Mat(size, CV_64FC2)),
                        radical::MatException);  // wrong channels
    MeanImage mi4(false, 0);
    BOOST_REQUIRE_THROW(mi4.add(cv::Mat(size, CV_32FC2), cv::Mat(size, CV_16UC1)),
                        radical::MatException);  // wrong type
    MeanImage mi5(false, 0);
    BOOST_REQUIRE_THROW(mi5.add(cv::Mat(size, CV_32FC1), cv::Mat(size, CV_32FC1)),
                        radical::MatException);  // wrong type
  }
}