OrientationSensor::OrientationSensor(uint8_t pin_i2c_sda, uint8_t pin_i2c_scl,
                                     uint8_t accel_mag_i2c_addr,
                                     uint8_t gyro_i2c_addr) {
  sensor_interface_ = new SensorFusion();  // create our fusion engine instance

  bool success;
  // init IO subsystem, passing NULLs since we use Signal-K output instead.
  success =
      sensor_interface_->InitializeInputOutputSubsystem(NULL, NULL) &&
      // connect to the sensors.  Accelerometer and magnetometer are in same IC.
      sensor_interface_->InstallSensor(accel_mag_i2c_addr,
                                       SensorType::kMagnetometer) &&
      sensor_interface_->InstallSensor(accel_mag_i2c_addr,
                                       SensorType::kAccelerometer) &&
      // A thermometer (uncalibrated) is available in the
      // accelerometer/magnetometer IC.
      sensor_interface_->InstallSensor(accel_mag_i2c_addr,
                                       SensorType::kThermometer) &&
      sensor_interface_->InstallSensor(gyro_i2c_addr, SensorType::kGyroscope);
  if (!success) {
    debugE("Trouble installing sensors.");
  } else {
    sensor_interface_->Begin(pin_i2c_sda, pin_i2c_scl);
    debugI("Sensors connected & Fusion ready");

    // The Fusion Library, in build.h, defines how fast the ICs generate new
    // orientation data and how fast the fusion algorithm runs, using FUSION_HZ.
    // Usually this rate should be the same as ReadAndProcessSensors() is
    // called.
    const uint32_t kFusionIntervalMs = 1000.0 / FUSION_HZ;
    // Start periodic reads of sensor and running of fusion algorithm.
    app.onRepeat(kFusionIntervalMs,
                 [this]() { this->ReadAndProcessSensors(); });
  }

}