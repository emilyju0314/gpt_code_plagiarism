uint8_t APDS9930::getAmbientLightInt()
{
    uint8_t val;
    
    /* Read value from STATUS register */
    if( !wireReadDataByte(APDS9930_STATUS, val) ) {
        return ERROR;
    }
    
    /* Shift and mask out AINT bit */
    val = (val >> 4) & 0b00000001;
    
    return val;
}