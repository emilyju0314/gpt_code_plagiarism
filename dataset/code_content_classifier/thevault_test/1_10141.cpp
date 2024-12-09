TEST_F(VideoMetricsTest, EmptyFilesPSNR) {
  EXPECT_EQ(kEmptyFileReturnCode,
            I420PSNRFromFiles(empty_file_.c_str(), video_file_.c_str(),
                              kWidth, kHeight, &ssim_result_));
  EXPECT_EQ(kEmptyFileReturnCode,
            I420PSNRFromFiles(video_file_.c_str(), empty_file_.c_str(),
                              kWidth, kHeight, &ssim_result_));
}