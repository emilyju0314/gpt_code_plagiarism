bool AttitudeValues::set_configuration(const JsonObject& config) {
  String expected[] = {"report_interval", "save_mag_cal"};
  for (auto str : expected) {
    if (!config.containsKey(str)) {
      return false;
    }
  }
  report_interval_ms_ = config["report_interval"];
  save_mag_cal_ = config["save_mag_cal"];
  return true;
}