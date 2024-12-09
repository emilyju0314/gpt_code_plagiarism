int AMS_5600::readOneByte(int in_adr)
{
  int retVal = -1;
  Wire.beginTransmission(_ams5600_Address);
  Wire.write(in_adr);
  Wire.endTransmission();
  Wire.requestFrom(_ams5600_Address, (uint8_t) 1);
  while (Wire.available() == 0)
    ;
  retVal = Wire.read();

  return retVal;
}