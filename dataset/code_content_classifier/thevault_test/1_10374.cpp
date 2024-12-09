TEST_F(EstimateAffineTransformTest, DISABLED_DestNotGreyscale) {
  Mat colorImage;

  cvtColor(image, colorImage, CV_GRAY2BGR);

  EXPECT_THROW(estimator->EstimateTransform(image, colorImage), cv::Exception);
}