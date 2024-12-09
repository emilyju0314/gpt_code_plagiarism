uint8_t APDS9930::getMode()
{
    uint8_t enable_value;
    
    /* Read current ENABLE register */
    if( !wireReadDataByte(APDS9930_ENABLE, enable_value) ) {
        return ERROR;
    }
    
    return enable_value;
}