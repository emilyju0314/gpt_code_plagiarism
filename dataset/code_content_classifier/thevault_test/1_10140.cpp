TEST_F(VideoMetricsTest, MissingTestFilePSNR) {
  EXPECT_EQ(kMissingTestFileReturnCode,
            I420PSNRFromFiles(video_file_.c_str(), non_existing_file_.c_str(),
                              kWidth, kHeight, &ssim_result_));
}