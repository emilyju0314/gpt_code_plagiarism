void OrientationSensor::ReadAndProcessSensors(void) {
  sensor_interface_->ReadSensors();
  sensor_interface_->RunFusion();

}