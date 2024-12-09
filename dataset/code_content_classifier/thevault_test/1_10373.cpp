TEST_F(EstimateAffineTransformTest, DISABLED_SrcNotGreyscale) {
  Mat colorImage;

  cvtColor(image, colorImage, CV_GRAY2BGR);

  EXPECT_THROW(estimator->EstimateTransform(colorImage, image), cv::Exception);
}