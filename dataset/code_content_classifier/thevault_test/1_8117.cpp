TangoErrorType MarkerDetectionApp::SetupImageBufferManager() {
  if (image_buffer_manager_ == nullptr) {
    TangoErrorType status = TangoSupport_createImageBufferManager(
        TANGO_HAL_PIXEL_FORMAT_YCrCb_420_SP, color_camera_intrinsics_.width,
        color_camera_intrinsics_.height, &image_buffer_manager_);
    if (status != TANGO_SUCCESS) {
      LOGE(
          "MarkerDetectionApp: Failed create image buffer manager "
          "with error code: %d",
          status);
      return status;
    }
  }
  return TANGO_SUCCESS;
}