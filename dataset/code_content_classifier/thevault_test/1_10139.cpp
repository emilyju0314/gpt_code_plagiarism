TEST_F(VideoMetricsTest, MissingReferenceFilePSNR) {
  EXPECT_EQ(kMissingReferenceFileReturnCode,
            I420PSNRFromFiles(non_existing_file_.c_str(),
                              video_file_.c_str(), kWidth, kHeight,
                              &ssim_result_));
}