bool APDS9930::wireWriteDataByte(uint8_t reg, uint8_t val)
{
    Wire.beginTransmission(APDS9930_I2C_ADDR);
    Wire.write(reg | AUTO_INCREMENT);
    Wire.write(val);
    if( Wire.endTransmission() != 0 ) {
        return false;
    }

    return true;
}