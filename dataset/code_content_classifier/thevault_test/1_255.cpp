OrientationValues::OrientationValues(OrientationSensor* orientation_sensor,
                                     OrientationValType val_type,
                                     uint report_interval_ms, String config_path)
    : NumericSensor(config_path),
      orientation_sensor_{orientation_sensor},
      value_type_{val_type},
      report_interval_ms_{report_interval_ms} {
  load_configuration();
  save_mag_cal_ = 0;

}