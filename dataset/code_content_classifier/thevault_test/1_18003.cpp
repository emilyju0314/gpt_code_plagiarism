TEST_P(DatarateOnePassCbrSvc, OnePassCbrSvc2SL1TLScreenContent1) {
  cfg_.rc_buf_initial_sz = 500;
  cfg_.rc_buf_optimal_sz = 500;
  cfg_.rc_buf_sz = 1000;
  cfg_.rc_min_quantizer = 0;
  cfg_.rc_max_quantizer = 63;
  cfg_.rc_end_usage = VPX_CBR;
  cfg_.g_lag_in_frames = 0;
  cfg_.ss_number_layers = 2;
  cfg_.ts_number_layers = 1;
  cfg_.ts_rate_decimator[0] = 1;
  cfg_.g_error_resilient = 1;
  cfg_.g_threads = 1;
  cfg_.temporal_layering_mode = 0;
  svc_params_.scaling_factor_num[0] = 144;
  svc_params_.scaling_factor_den[0] = 288;
  svc_params_.scaling_factor_num[1] = 288;
  svc_params_.scaling_factor_den[1] = 288;
  cfg_.rc_dropframe_thresh = 10;
  cfg_.kf_max_dist = 9999;
  number_spatial_layers_ = cfg_.ss_number_layers;
  number_temporal_layers_ = cfg_.ts_number_layers;
  ::libvpx_test::Y4mVideoSource video("niklas_1280_720_30.y4m", 0, 60);
  cfg_.rc_target_bitrate = 500;
  ResetModel();
  tune_content_ = 1;
  base_speed_setting_ = speed_setting_;
  assign_layer_bitrates(&cfg_, &svc_params_, cfg_.ss_number_layers,
                        cfg_.ts_number_layers, cfg_.temporal_layering_mode,
                        layer_target_avg_bandwidth_, bits_in_buffer_model_);
  ASSERT_NO_FATAL_FAILURE(RunLoop(&video));
  CheckLayerRateTargeting(&cfg_, number_spatial_layers_,
                          number_temporal_layers_, file_datarate_, 0.78, 1.15);
  EXPECT_EQ(static_cast<unsigned int>(0), GetMismatchFrames());
}