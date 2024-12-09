bool APDS9930::wireReadDataByte(uint8_t reg, uint8_t &val)
{
    
    /* Indicate which register we want to read from */
    if (!wireWriteByte(reg | AUTO_INCREMENT)) {
        return false;
    }
    
    /* Read from register */
    Wire.requestFrom(APDS9930_I2C_ADDR, 1);
    while (Wire.available()) {
        val = Wire.read();
    }

    return true;
}