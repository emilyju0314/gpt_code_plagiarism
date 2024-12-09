bool VideoStabilizationApp::TangoConnect() {
  TangoErrorType ret = TangoService_connect(this, tango_config_);
  if (ret != TANGO_SUCCESS) {
    LOGE(
        "VideoStabilizationApp: Failed to connect to the Tango service with"
        "error code: %d",
        ret);
    return false;
  }

  // Initialize TangoSupport context.
  TangoSupport_initialize(TangoService_getPoseAtTime,
                          TangoService_getCameraIntrinsics);

  return true;
}