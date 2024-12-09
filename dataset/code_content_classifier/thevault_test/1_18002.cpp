TEST_P(DatarateTestVP9Large, ChangingDropFrameThresh) {
  cfg_.rc_buf_initial_sz = 500;
  cfg_.rc_buf_optimal_sz = 500;
  cfg_.rc_buf_sz = 1000;
  cfg_.rc_undershoot_pct = 20;
  cfg_.rc_undershoot_pct = 20;
  cfg_.rc_dropframe_thresh = 10;
  cfg_.rc_min_quantizer = 0;
  cfg_.rc_max_quantizer = 50;
  cfg_.rc_end_usage = VPX_CBR;
  cfg_.rc_target_bitrate = 200;
  cfg_.g_lag_in_frames = 0;
  // TODO(marpan): Investigate datarate target failures with a smaller keyframe
  // interval (128).
  cfg_.kf_max_dist = 9999;

  ::libvpx_test::I420VideoSource video("hantro_collage_w352h288.yuv", 352, 288,
                                       30, 1, 0, 140);

  const int kDropFrameThreshTestStep = 30;
  for (int j = 50; j <= 150; j += 100) {
    cfg_.rc_target_bitrate = j;
    vpx_codec_pts_t last_drop = 140;
    int last_num_drops = 0;
    for (int i = 10; i < 100; i += kDropFrameThreshTestStep) {
      cfg_.rc_dropframe_thresh = i;
      ResetModel();
      ASSERT_NO_FATAL_FAILURE(RunLoop(&video));
      ASSERT_GE(effective_datarate_[0], cfg_.rc_target_bitrate * 0.85)
          << " The datarate for the file is lower than target by too much!";
      ASSERT_LE(effective_datarate_[0], cfg_.rc_target_bitrate * 1.25)
          << " The datarate for the file is greater than target by too much!";
      ASSERT_LE(first_drop_, last_drop)
          << " The first dropped frame for drop_thresh " << i
          << " > first dropped frame for drop_thresh "
          << i - kDropFrameThreshTestStep;
      ASSERT_GE(num_drops_, last_num_drops * 0.85)
          << " The number of dropped frames for drop_thresh " << i
          << " < number of dropped frames for drop_thresh "
          << i - kDropFrameThreshTestStep;
      last_drop = first_drop_;
      last_num_drops = num_drops_;
    }
  }
}