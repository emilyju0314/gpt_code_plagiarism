bool CameraLocalization::CreateLocalizationMsg(
    const ::apollo::localization::Gps &gps_msg,
    const ::apollo::localization::Camera &camera_msg,
    LocalizationEstimate *localization) {
  localization->Clear();

  // header
  AdapterManager::FillLocalizationHeader(FLAGS_localization_module_name,
                                         localization->mutable_header());
  if (FLAGS_enable_gps_timestamp) {
    // copy time stamp, do NOT use Clock::Now()
    localization->mutable_header()->set_timestamp_sec(
        gps_msg.header().timestamp_sec());
  }

  if (!gps_msg.has_localization()) {
    AERROR << "GPS has no localization field";
    return false;
  }

  if (!camera_msg.has_image() || !camera_msg.has_width() ||
      !camera_msg.has_height()) {
    AERROR << "camera data is invalid";
    return false;
  }

  // TODO(Dong): Get high accuracy position information from gps and camera
  // image.
  // const auto &gps_location = gps_msg.localization();
  // const auto &image = camera_msg.image();
  // const auto image_width = camera_msg.width();
  // const auto image_height = camera_msg.height();
  return true;
}