TEST_P(DatarateOnePassCbrSvc, OnePassCbrSvc2SL3TL) {
  cfg_.rc_buf_initial_sz = 500;
  cfg_.rc_buf_optimal_sz = 500;
  cfg_.rc_buf_sz = 1000;
  cfg_.rc_min_quantizer = 0;
  cfg_.rc_max_quantizer = 63;
  cfg_.rc_end_usage = VPX_CBR;
  cfg_.g_lag_in_frames = 0;
  cfg_.ss_number_layers = 2;
  cfg_.ts_number_layers = 3;
  cfg_.ts_rate_decimator[0] = 4;
  cfg_.ts_rate_decimator[1] = 2;
  cfg_.ts_rate_decimator[2] = 1;
  cfg_.g_error_resilient = 1;
  cfg_.g_threads = 1;
  cfg_.temporal_layering_mode = 3;
  svc_params_.scaling_factor_num[0] = 144;
  svc_params_.scaling_factor_den[0] = 288;
  svc_params_.scaling_factor_num[1] = 288;
  svc_params_.scaling_factor_den[1] = 288;
  cfg_.rc_dropframe_thresh = 0;
  cfg_.kf_max_dist = 9999;
  number_spatial_layers_ = cfg_.ss_number_layers;
  number_temporal_layers_ = cfg_.ts_number_layers;
  ::libvpx_test::I420VideoSource video("niklas_640_480_30.yuv", 640, 480, 30, 1,
                                       0, 400);
  // TODO(marpan): Check that effective_datarate for each layer hits the
  // layer target_bitrate.
  for (int i = 200; i <= 800; i += 200) {
    cfg_.rc_target_bitrate = i;
    ResetModel();
    assign_layer_bitrates(&cfg_, &svc_params_, cfg_.ss_number_layers,
                          cfg_.ts_number_layers, cfg_.temporal_layering_mode,
                          layer_target_avg_bandwidth_, bits_in_buffer_model_);
    ASSERT_NO_FATAL_FAILURE(RunLoop(&video));
    CheckLayerRateTargeting(&cfg_, number_spatial_layers_,
                            number_temporal_layers_, file_datarate_, 0.78,
                            1.15);
#if CONFIG_VP9_DECODER
    // Number of temporal layers > 1, so half of the frames in this SVC pattern
    // will be non-reference frame and hence encoder will avoid loopfilter.
    // Since frame dropper is off, we can expect 200 (half of the sequence)
    // mismatched frames.
    EXPECT_EQ(static_cast<unsigned int>(200), GetMismatchFrames());
#endif
  }
}