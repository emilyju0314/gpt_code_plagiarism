uint8_t APDS9930::getProximityInt()
{
    uint8_t val;
    
    /* Read value from STATUS register */
    if( !wireReadDataByte(APDS9930_STATUS, val) ) {
        return ERROR;
    }
    
    /* Shift and mask out PINT bit */
    val = (val >> 5) & 0b00000001;
    
    return val;
}