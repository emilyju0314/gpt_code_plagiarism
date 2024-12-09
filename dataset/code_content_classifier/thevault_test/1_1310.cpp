bool APDS9930::readAmbientLightLux(float &val)
{
    uint16_t Ch0;
    uint16_t Ch1;
    
    /* Read value from channel 0 */
    if( !readCh0Light(Ch0) ) {
        return false;
    }

    /* Read value from channel 1 */
    if( !readCh1Light(Ch1) ) {
        return false;
    }

    val = floatAmbientToLux(Ch0, Ch1);
    return true;
}