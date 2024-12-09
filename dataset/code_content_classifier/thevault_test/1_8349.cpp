void Adafruit_MPR121_mod::setThresholds(uint8_t touch, uint8_t release) {
  // first stop sensor to make changes
  // writeRegister(MPR121_ECR, 0x00);
  // set all thresholds (the same)
  for (uint8_t i = 0; i < 12; i++) {
    writeRegister(MPR121_TOUCHTH_0 + 2 * i, touch);
    writeRegister(MPR121_RELEASETH_0 + 2 * i, release);
  }
  // turn the sensor on again
  // writeRegister(MPR121_ECR, 0x8F);
}