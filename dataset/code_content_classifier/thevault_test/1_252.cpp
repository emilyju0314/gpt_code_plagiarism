AttitudeValues::AttitudeValues(OrientationSensor* orientation_sensor,
                               uint report_interval_ms, String config_path)
    : Sensor(config_path),
      orientation_sensor_{orientation_sensor},
      report_interval_ms_{report_interval_ms} {
  load_configuration();
  save_mag_cal_ = 0;
}