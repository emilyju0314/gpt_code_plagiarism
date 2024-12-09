TEST_F(VideoMetricsTest, ReturnsPerfectResultForIdenticalFilesPSNR) {
  EXPECT_EQ(0, I420PSNRFromFiles(video_file_.c_str(), video_file_.c_str(),
                                 kWidth, kHeight, &psnr_result_));
  EXPECT_EQ(kPsnrPerfectResult, psnr_result_.average);
}