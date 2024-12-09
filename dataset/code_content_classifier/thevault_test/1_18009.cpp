TEST_P(DatarateOnePassCbrSvc, OnePassCbrSvc3SL3TLSmallKf) {
  cfg_.rc_buf_initial_sz = 500;
  cfg_.rc_buf_optimal_sz = 500;
  cfg_.rc_buf_sz = 1000;
  cfg_.rc_min_quantizer = 0;
  cfg_.rc_max_quantizer = 63;
  cfg_.rc_end_usage = VPX_CBR;
  cfg_.g_lag_in_frames = 0;
  cfg_.ss_number_layers = 3;
  cfg_.ts_number_layers = 3;
  cfg_.ts_rate_decimator[0] = 4;
  cfg_.ts_rate_decimator[1] = 2;
  cfg_.ts_rate_decimator[2] = 1;
  cfg_.g_error_resilient = 1;
  cfg_.g_threads = 1;
  cfg_.temporal_layering_mode = 3;
  svc_params_.scaling_factor_num[0] = 72;
  svc_params_.scaling_factor_den[0] = 288;
  svc_params_.scaling_factor_num[1] = 144;
  svc_params_.scaling_factor_den[1] = 288;
  svc_params_.scaling_factor_num[2] = 288;
  svc_params_.scaling_factor_den[2] = 288;
  cfg_.rc_dropframe_thresh = 10;
  cfg_.rc_target_bitrate = 800;
  number_spatial_layers_ = cfg_.ss_number_layers;
  number_temporal_layers_ = cfg_.ts_number_layers;
  ::libvpx_test::I420VideoSource video("niklas_640_480_30.yuv", 640, 480, 30, 1,
                                       0, 400);
  // For this 3 temporal layer case, pattern repeats every 4 frames, so choose
  // 4 key neighboring key frame periods (so key frame will land on 0-2-1-2).
  for (int j = 32; j <= 35; j++) {
    cfg_.kf_max_dist = j;
    ResetModel();
    assign_layer_bitrates(&cfg_, &svc_params_, cfg_.ss_number_layers,
                          cfg_.ts_number_layers, cfg_.temporal_layering_mode,
                          layer_target_avg_bandwidth_, bits_in_buffer_model_);
    ASSERT_NO_FATAL_FAILURE(RunLoop(&video));
    CheckLayerRateTargeting(&cfg_, number_spatial_layers_,
                            number_temporal_layers_, file_datarate_, 0.78,
                            1.15);
  }
}