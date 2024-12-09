BOOST_AUTO_TEST_CASE(AddMatCompatibilty) {
  cv::Mat image1(10, 5, CV_32FC3);
  cv::Mat image2(10, 5, CV_32FC2);
  cv::Mat image3(10, 5, CV_8UC1);
  cv::Mat image4(10, 5, CV_8UC3);
  cv::Mat image5(5, 10, CV_8UC3);
  cv::Mat image6(5, 10, CV_8UC1);
  cv::Mat image7(1, 5, CV_32FC3);
  cv::Mat image8(1, 5, CV_32FC2);

  // Every image should match the first one
  {
    MeanImage mi(false, 0);
    BOOST_REQUIRE_NO_THROW(mi.add(image1));
    BOOST_REQUIRE_NO_THROW(mi.add(image1));                      // same image, no throw
    BOOST_REQUIRE_NO_THROW(mi.add(image1));                      // same image, no throw
    BOOST_REQUIRE_THROW(mi.add(image2), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image3), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image4), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image5), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image6), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image7), radical::MatException);  // different size/type
    BOOST_REQUIRE_THROW(mi.add(image8), radical::MatException);  // different size/type
  }

  // Reset after every addition → no exceptions
  {
    MeanImage mi(false, 1);
    BOOST_REQUIRE_NO_THROW(mi.add(image1));
    BOOST_REQUIRE_NO_THROW(mi.add(image2));
    BOOST_REQUIRE_NO_THROW(mi.add(image3));
    BOOST_REQUIRE_NO_THROW(mi.add(image4));
  }
}