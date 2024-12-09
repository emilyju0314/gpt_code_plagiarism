int8_t Bsec::i2cWrite(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len) {
#ifdef DEBUG_i2c
  Serial.print("\tI2C $"); Serial.print(reg_addr, HEX); Serial.print(" <= ");
#endif
  Bsec::wireObj->beginTransmission((uint8_t)dev_id);
  Bsec::wireObj->write((uint8_t)reg_addr);
  while (len--) {
    Bsec::wireObj->write(*reg_data);
#ifdef DEBUG_i2c
    Serial.print("0x"); Serial.print(*reg_data, HEX); Serial.print(", ");
#endif
    reg_data++;
  }
  Bsec::wireObj->endTransmission();
#ifdef DEBUG_i2c
  Serial.println("");
#endif
  return 0;
}