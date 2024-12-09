bool APDS9930::wireWriteByte(uint8_t val)
{
    Wire.beginTransmission(APDS9930_I2C_ADDR);
    Wire.write(val);
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    
    return true;
}