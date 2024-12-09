TEST_P(DatarateTestVP9Large, BasicRateTargetingVBRLagNonZero) {
  cfg_.rc_min_quantizer = 0;
  cfg_.rc_max_quantizer = 63;
  cfg_.g_error_resilient = 0;
  cfg_.rc_end_usage = VPX_VBR;
  // For non-zero lag, rate control will work (be within bounds) for
  // real-time mode.
  if (deadline_ == VPX_DL_REALTIME) {
    cfg_.g_lag_in_frames = 15;
  } else {
    cfg_.g_lag_in_frames = 0;
  }

  ::libvpx_test::I420VideoSource video("hantro_collage_w352h288.yuv", 352, 288,
                                       30, 1, 0, 300);
  for (int i = 400; i <= 800; i += 400) {
    cfg_.rc_target_bitrate = i;
    ResetModel();
    ASSERT_NO_FATAL_FAILURE(RunLoop(&video));
    ASSERT_GE(effective_datarate_[0], cfg_.rc_target_bitrate * 0.75)
        << " The datarate for the file is lower than target by too much!";
    ASSERT_LE(effective_datarate_[0], cfg_.rc_target_bitrate * 1.30)
        << " The datarate for the file is greater than target by too much!";
  }
}