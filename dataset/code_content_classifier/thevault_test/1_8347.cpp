boolean Adafruit_MPR121_mod::init( uint8_t touchThreshold,
                               uint8_t releaseThreshold,
                               bool autoconfigEnabled) 
{
  // soft reset
  writeRegister(MPR121_SOFTRESET, 0x63);
  delay(10);
  for (uint8_t i = 0; i < 0x7F; i++) {
    //  Serial.print("$"); Serial.print(i, HEX);
    //  Serial.print(": 0x"); Serial.println(readRegister8(i));
  }

  uint8_t c = readRegister8(MPR121_CONFIG2);

  if (c != 0x24)
    return false;

  // writeRegister(MPR121_ECR, 0x0); unneeded! 

  setThresholds(touchThreshold, releaseThreshold);
  writeRegister(MPR121_MHDR, 0x01); ///< Maximum Half Delta Rising, value 1-63: largest magnitude passing through
  writeRegister(MPR121_NHDR, 0x05); ///< Noise Half Delta Rising, value 1-63: incremental for non-noise drift
  writeRegister(MPR121_NCLR, 0x01); ///< Noise Count Limit Rising, value 0-255: number of samples consecutively greater than MHDR
  writeRegister(MPR121_FDLR, 0x00); ///< Filter Delay Count Limit Rising, value 0-255: operation rate of filter, 0: fastest, 255: slowest

  writeRegister(MPR121_MHDF, 0x06); ///< Maximum Half Delta Falling, value 1-63: largest magnitude passing through
  writeRegister(MPR121_NHDF, 0x05); ///< Noise Half Delta Falling, value 1-63: .... so on
  writeRegister(MPR121_NCLF, 0x01);
  writeRegister(MPR121_FDLF, 0x00);

  writeRegister(MPR121_NHDT, 0x00); ///< Noise Half Delta Touch ... and so on
  writeRegister(MPR121_NCLT, 0x00);
  writeRegister(MPR121_FDLT, 0x00);
  
  ///< more: see Application Note AN3891

  writeRegister(MPR121_DEBOUNCE, 0);
  writeRegister(MPR121_CONFIG1, 0x10); // default, 16uA charge current
  writeRegister(MPR121_CONFIG2, 0x20); // 0.5uS encoding, 1ms period

  if (autoconfigEnabled)
  {
    writeRegister(MPR121_AUTOCONFIG0, 0x0B);

    // correct values for Vdd = 3.3V
    writeRegister(MPR121_UPLIMIT, 200);     // ((Vdd - 0.7)/Vdd) * 256
    writeRegister(MPR121_TARGETLIMIT, 180); // UPLIMIT * 0.9
    writeRegister(MPR121_LOWLIMIT, 130);    // UPLIMIT * 0.65
  }
  else
  {
    /* do not set up electrodes automatically */
  }

  return true;
}