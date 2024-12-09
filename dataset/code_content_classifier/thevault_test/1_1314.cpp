uint16_t APDS9930::getProximityIntHighThreshold()
{
    uint16_t val;
    uint8_t val_byte;
    
    /* Read value from PILT register */
    if( !wireReadDataByte(APDS9930_PIHTL, val_byte) ) {
        val = 0;
    }
    val = val_byte;
    if( !wireReadDataByte(APDS9930_PIHTH, val_byte) ) {
        val = 0;
    }
    val |= ((uint16_t)val_byte << 8);    
    
    return val;
}