bool APDS9930::readProximity(uint16_t &val)
{
    val = 0;
    uint8_t val_byte;

    /* Read value from proximity data register */
    if( !wireReadDataByte(APDS9930_PDATAL, val_byte) ) {
        return false;
    }
    val = val_byte;
    if( !wireReadDataByte(APDS9930_PDATAH, val_byte) ) {
        return false;
    }
    val += ((uint16_t)val_byte << 8);
    
    return true;
}