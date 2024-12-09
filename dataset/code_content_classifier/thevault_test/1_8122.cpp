void MeshBuilderApp::TangoConnect() {
  TangoErrorType err = TangoService_connect(this, tango_config_);
  if (err != TANGO_SUCCESS) {
    LOGE(
        "MeshBuilderApp: Failed to connect to the Tango service with"
        "error code: %d",
        err);
    std::exit(EXIT_SUCCESS);
  }

  // Initialize TangoSupport context.
  TangoSupport_initialize(TangoService_getPoseAtTime,
                          TangoService_getCameraIntrinsics);

  // Update the camera intrinsics too.
  TangoCameraIntrinsics intrinsics;
  err = TangoService_getCameraIntrinsics(TANGO_CAMERA_COLOR, &intrinsics);
  if (err != TANGO_SUCCESS) {
    LOGE(
        "MeshBuilderApp: Failed to get camera intrinsics with error "
        "code: %d",
        err);
    std::exit(EXIT_SUCCESS);
  }
  t3dr_intrinsics_.calibration_type =
      static_cast<Tango3DR_TangoCalibrationType>(intrinsics.calibration_type);
  t3dr_intrinsics_.width = intrinsics.width;
  t3dr_intrinsics_.height = intrinsics.height;
  t3dr_intrinsics_.fx = intrinsics.fx;
  t3dr_intrinsics_.fy = intrinsics.fy;
  t3dr_intrinsics_.cx = intrinsics.cx;
  t3dr_intrinsics_.cy = intrinsics.cy;
  std::copy(std::begin(intrinsics.distortion), std::end(intrinsics.distortion),
            std::begin(t3dr_intrinsics_.distortion));
}